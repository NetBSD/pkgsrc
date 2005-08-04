# $NetBSD: Makefile,v 1.14.2.1 2005/08/04 22:22:14 salo Exp $
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
MAKE_ENV+=		LIBS=${LIBS:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
