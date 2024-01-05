# $NetBSD: Makefile,v 1.6 2024/01/05 14:41:20 bacon Exp $

DISTNAME=	dte-1.11.1
CATEGORIES=	editors
MASTER_SITES=	https://craigbarnes.gitlab.io/dist/dte/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://craigbarnes.gitlab.io/dte/
COMMENT=	Small and easy to use console text editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
