# $NetBSD: Makefile,v 1.5 2004/03/29 00:30:16 xtraeme Exp $

DISTNAME=	XFree86-4.4.0-src-4
PKGNAME=	XFree86-fontsEncodings-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Encoding fonts

DEPENDS=	XFree86-clients>=4.4.0:../../x11/XFree86-clients

NO_XFREE86_TARGETS=	# defined
CHECK_X11_TYPE=		# defined
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
