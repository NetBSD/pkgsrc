# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 08:59:39 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsScalable-${XF_VER}
WRKSRC=		${WRKDIR}/xc/fonts
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	X430src-4.tgz X430src-5.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 scalable fonts

DEPENDS+=	XFree86-fontsEncodings>=4.3.0:../../fonts/XFree86-fontsEncodings

USE_BUILDLINK2=		YES
NO_XFREE86_TARGETS=	# defined

FILESDIR=	${.CURDIR}/../../fonts/XFree86-fontsEncodings/files

do-configure:
	@${SED} \
		-e "s|@PREFIX@|${X11PREFIX}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def
	@${LN} -sf ${WRKSRC}/host.def ${WRKDIR}/xc/fonts/encodings
	@${LN} -sf ${WRKSRC}/host.def ${WRKDIR}/xc/fonts/encodings/large
	(cd ${WRKSRC}/encodings && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

pre-build:
	@for dir in Type1 TTF ; do \
		${MV} ${WRKSRC}/scaled/$${dir}/Makefile \
			${WRKSRC}/scaled/$${dir}/Makefile.orig && \
		${SED} -e 's|$$(BINDIR)/fc-cache|${LOCALBASE}/bin/fc-cache|' \
			${WRKSRC}/scaled/$${dir}/Makefile.orig \
			> ${WRKSRC}/scaled/$${dir}/Makefile ; \
	done
	cd ${WRKSRC}/encodings && \
		${MAKE} all

pre-install:
	${LN} -sf ${WRKDIR}/xc/fonts ${WRKDIR}/fonts

.include "../../meta-pkgs/XFree86/Makefile.common"

.include "../../mk/bsd.pkg.mk"
