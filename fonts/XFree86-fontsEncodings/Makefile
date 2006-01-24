# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:07 wiz Exp $

DISTNAME=	XFree86-${XF_VER}-src-4
PKGNAME=	XFree86-fontsEncodings-${XF_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Encoding fonts

BUILD_DEPENDS+=	XFree86-clients>=${XF_VER}:../../x11/XFree86-clients

NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}/xc/fonts/encodings

post-extract:
	@${SED} \
		-e 's,@PREFIX@,${X11ROOT},g' \
		-e 's,@MAKE@,${MAKE_PROGRAM},g' \
		-e 's,@IMAKE@,${IMAKE},g' \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

do-configure:
	(cd ${WRKSRC} && \
	${IMAKE} -DUseInstalled -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
