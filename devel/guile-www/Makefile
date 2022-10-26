# $NetBSD: Makefile,v 1.43 2022/10/26 10:31:22 wiz Exp $

DISTNAME=	guile-www-2.42
PKGREVISION=	2
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
