# $NetBSD: Makefile,v 1.5 2023/08/11 08:44:16 nia Exp $

DISTNAME=	dte-1.9.1
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
