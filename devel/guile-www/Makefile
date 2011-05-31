# $NetBSD: Makefile,v 1.28 2011/05/31 11:53:52 gdt Exp $

DISTNAME=	guile-www-2.31
CATEGORIES=	devel www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-www/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/guile-www/
COMMENT=	Guile WWW module

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
INFO_FILES=	YES

TEST_TARGET=	check

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
