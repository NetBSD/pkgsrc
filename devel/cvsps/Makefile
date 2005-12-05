# $NetBSD: Makefile,v 1.17 2005/12/05 20:50:03 rillig Exp $
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
MAKE_ENV+=		LIBS=${LIBS:M*:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
