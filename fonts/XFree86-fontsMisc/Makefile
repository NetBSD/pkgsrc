# $NetBSD: Makefile,v 1.3 2004/02/02 14:19:02 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsMisc-${XF_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-1.tgz X430src-4.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 default bitmap fonts

DEPENDS=	XFree86-fontsEncodings>=4.3.0:../../fonts/XFree86-fontsEncodings

WRKSRC=			${WRKDIR}/xc/fonts/bdf/misc
USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined
EXTRACT_ONLY=		X430src-4.tgz

FILESDIR=	${.CURDIR}/../../fonts/XFree86-fontsEncodings/files

post-extract:
	cd ${WRKDIR} && \
		${GUNZIP_CMD} -c ${DISTDIR}/X430src-1.tgz | ${GTAR} -xf - \
		xc/extras/fonts/arabic24 xc/extras/fonts/ClearlyU;
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
		-DTOPDIR=../.. -DCURDIR=.; \
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
