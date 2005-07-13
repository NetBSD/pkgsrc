# $NetBSD: Makefile,v 1.15 2005/07/13 04:00:41 schmonz Exp $
#

DISTNAME=	cvsps-2.1
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.cobite.com/cvsps/
COMMENT=	Generates 'patchset' information from a CVS repository

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin man/man1

LIBS.SunOS+=		-lnsl -lsocket

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
