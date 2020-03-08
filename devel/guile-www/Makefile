# $NetBSD: Makefile,v 1.39 2020/03/08 16:49:13 wiz Exp $

DISTNAME=	guile-www-2.39
PKGREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-www/
EXTRACT_SUFX=	.tar.xz

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
