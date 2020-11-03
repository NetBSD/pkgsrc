# $NetBSD: Makefile,v 1.28 2020/11/03 11:09:19 schmonz Exp $
#

DISTNAME=	check-0.15.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libcheck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://check.sourceforge.net/
COMMENT=	Unit test framework for C
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	ac_cv_path_AWK_PATH=gawk
USE_TOOLS=	automake autoreconf makeinfo pkg-config # gawk
USE_LIBTOOL=	yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE=	check.pc.in

CONFIGURE_ARGS+=	--enable-build-docs=no

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
