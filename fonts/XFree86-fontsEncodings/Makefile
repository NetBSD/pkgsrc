# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 08:57:34 xtraeme Exp $

DISTNAME=	X430src-4
PKGNAME=	XFree86-fontsEncodings-${XF_VER}
WRKSRC=		${WRKDIR}/xc/fonts/encodings
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Encoding fonts

DEPENDS=	XFree86-clients>=4.3.0:../../x11/XFree86-clients

USE_BUILDLINK2=		yes
NO_XFREE86_TARGETS=	# defined

post-extract:
	@${SED} \
		-e "s|@PREFIX@|${X11PREFIX}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

do-configure:
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../meta-pkgs/XFree86/Makefile.common"

.include "../../mk/bsd.pkg.mk"
