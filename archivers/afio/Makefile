# $NetBSD: Makefile,v 1.4 2004/04/11 23:04:50 minskim Exp $

DISTNAME=	afio-2.5
CATEGORIES=	archivers
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/system/backup/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/afio/
COMMENT=	cpio-format archive creator with data corruption handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
ALL_TARGET=	afio

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.pkg.mk"
