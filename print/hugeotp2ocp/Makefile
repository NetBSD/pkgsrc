# $NetBSD: Makefile,v 1.5 2008/02/04 20:10:34 tnn Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:S/tetex-src/hugeotp2ocp/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Utility to convert large OTP to OCP

DIST_SUBDIR=	teTeX
DISTINFO_FILE=	${.CURDIR}/../../print/teTeX3-bin/distinfo
PATCHDIR=	${.CURDIR}/../../print/teTeX3-bin/patches

GNU_CONFIGURE=	yes
BUILD_DIRS=	${WRKSRC}/texk/web2c/lib
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	lex

CONFIGURE_ARGS+=	--without-texinfo
CONFIGURE_ARGS+=	--without-dialog
CONFIGURE_ARGS+=	--without-xdvik
CONFIGURE_ARGS+=	--disable-multiplatform

TEX_ACCEPTED=	teTeX3

BUILDLINK_DEPMETHOD.teTeX-bin=	build
.include "../../mk/tex.buildlink3.mk"

post-configure:
	cd ${WRKSRC}/texk/web2c/otps; \
	${PATCH} -p0 < ${FILESDIR}/otps.Makefile.patch; \
	${PATCH} -p0 < ${FILESDIR}/otps.routines.h.patch

post-build:
	cd ${WRKSRC}/texk/web2c/otps; \
	${SETENV} ${MAKE_ENV} ${MAKE} otp2ocp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/otps/otp2ocp \
		${PREFIX}/bin/hugeotp2ocp

.include "../../mk/bsd.pkg.mk"
