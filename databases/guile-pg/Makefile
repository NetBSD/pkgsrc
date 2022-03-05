# $NetBSD: Makefile,v 1.59 2022/03/05 15:00:16 gdt Exp $

DISTNAME=	guile-pg-0.50
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-pg/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/guile-pg/
COMMENT=	PostgreSQL interface for Guile
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES
INFO_FILES=	YES

CONFIGURE_ENV+=	GUILE_AUTO_COMPILE=0

# Remediate anti-libtool bias.
MAKE_FLAGS+=	SOFIXFLAGS=no-symlinks
BUILD_ENV+=	GUILE_AUTO_COMPILE=0

TEST_TARGET=	check
# To run tests without compiling
TEST_ENV+=	GUILE_AUTO_COMPILE=0
TEST_ENV+=	VERBOSE=1
TEST_ENV+=	DEBUG=1

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
