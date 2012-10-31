# $NetBSD: Makefile,v 1.30 2012/10/31 11:17:05 asau Exp $

DISTNAME=	guile-www-2.32
CATEGORIES=	devel www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-www/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/guile-www/
COMMENT=	Guile WWW module

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
INFO_FILES=	YES

TEST_TARGET=	check

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
