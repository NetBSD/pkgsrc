# $NetBSD: Makefile,v 1.41 2021/12/19 14:12:29 gdt Exp $

DISTNAME=	guile-www-2.42
#PKGREVISION=	0
CATEGORIES=	devel www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-www/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/guile-www/
COMMENT=	Guile WWW module

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
INFO_FILES=	YES

TEST_TARGET=	check

.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
