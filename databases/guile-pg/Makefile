# $NetBSD: Makefile,v 1.55 2020/11/11 14:25:22 gdt Exp $

DISTNAME=	guile-pg-0.48
CATEGORIES=	databases
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-pg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/guile-pg/
COMMENT=	PostgreSQL interface for Guile
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	YES
INFO_FILES=	YES

# Remediate anti-libtool bias.
MAKE_FLAGS+=	SOFIXFLAGS=none

TEST_TARGET=	check
# To run tests without compiling
#TEST_ENV+=	GUILE_AUTO_COMPILE=0

# guile-pg currently supports only 1.8 and 2.0
.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
