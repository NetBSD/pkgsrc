# $NetBSD: Makefile,v 1.3 2004/02/02 14:19:01 xtraeme Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fontsCyrillic-${XF_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Cyrillic fonts

DEPENDS+=	XFree86-fontsEncodings>=4.3.0:../../fonts/XFree86-fontsEncodings

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined
WRKSRC=			${WRKDIR}/xc/fonts/bdf/cyrillic

FILESDIR=	${.CURDIR}/../../fonts/XFree86-fontsEncodings/files

post-extract:
	@${SED} \
		-e "s|@PREFIX@|${X11ROOT}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def
.for f in encodings encodings/large
	@${LN} -sf ${WRKSRC}/host.def ${WRKDIR}/xc/fonts/${f}
.endfor

do-configure:
	(cd ${WRKDIR}/xc/fonts/encodings && \
	${IMAKE} -DUseInstalled -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

pre-build:
	@${MV} ${WRKDIR}/xc/fonts/encodings/large/Makefile \
		${WRKDIR}/xc/fonts/encodings/large/Makefile.in
	@${SED} -e "s|/usr/X11R6|${X11ROOT}|g" \
	< ${WRKDIR}/xc/fonts/encodings/large/Makefile.in > \
	${WRKDIR}/xc/fonts/encodings/large/Makefile

	(cd ${WRKDIR}/xc/fonts/encodings && ${MAKE} all)

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
