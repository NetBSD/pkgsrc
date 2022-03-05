# $NetBSD: Makefile,v 1.42 2022/03/05 18:51:52 gdt Exp $

DISTNAME=	guile-www-2.42
PKGREVISION=	1
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

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
