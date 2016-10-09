# $NetBSD: Makefile,v 1.51 2016/10/09 21:41:56 wiz Exp $

DISTNAME=	guile-pg-0.47
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-pg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/guile-pg/
COMMENT=	PostgreSQL interface for Guile
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES
INFO_FILES=	YES

CONFIGURE_ARGS+=	--with-libpq=${PREFIX}

TEST_TARGET=	check
# To run tests without compiling
#TEST_ENV+=	GUILE_AUTO_COMPILE=0

.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
