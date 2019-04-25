# $NetBSD: Makefile,v 1.1 2017/11/24 06:46:01 kamil Exp $

DISTNAME=	dte-1.8.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=craigbarnes/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/craigbarnes/dte/
COMMENT=	Small and easy to use console text editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
