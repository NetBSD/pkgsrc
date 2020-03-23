# $NetBSD: Makefile,v 1.3 2020/03/23 20:00:47 nia Exp $

DISTNAME=	dte-1.9.1
CATEGORIES=	editors
MASTER_SITES=	https://craigbarnes.gitlab.io/dist/dte/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://craigbarnes.gitlab.io/dte/
COMMENT=	Small and easy to use console text editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
