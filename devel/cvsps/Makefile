# $NetBSD: Makefile,v 1.14 2005/05/22 20:07:50 jlam Exp $
#

DISTNAME=	cvsps-2.0rc1
PKGREVISION=	1
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
