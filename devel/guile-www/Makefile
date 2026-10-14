# $NetBSD: Makefile,v 1.44 2026/10/14 23:58:41 gdt Exp $

DISTNAME=	guile-www-2.42
PKGREVISION=	3
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

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
