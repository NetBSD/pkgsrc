# $NetBSD: Makefile,v 1.3 2019/12/28 12:16:53 mef Exp $

DISTNAME=	bfs-1.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tavianator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tavianator/bfs/
COMMENT=	Breadth-first version of the UNIX find command
LICENSE=	0-clause-bsd

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
