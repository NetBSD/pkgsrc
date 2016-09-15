# $NetBSD: Makefile,v 1.36 2016/09/15 14:32:40 wiz Exp $

DISTNAME=	guile-www-2.39
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://download.savannah.nongnu.org/releases/guile-www/
EXTRACT_SUFX=	.tar.xz

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
