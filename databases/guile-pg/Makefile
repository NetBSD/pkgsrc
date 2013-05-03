# $NetBSD: Makefile,v 1.47 2013/05/03 15:23:35 gdt Exp $
#

DISTNAME=	guile-pg-0.46
CATEGORIES=	databases
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-pg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/guile-pg/
COMMENT=	PostgreSQL interface for Guile
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
INFO_FILES=	YES

CONFIGURE_ARGS+=	--with-libpq=${PREFIX}

TEST_TARGET=	check

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
