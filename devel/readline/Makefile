# $NetBSD: Makefile,v 1.36 2005/12/31 00:01:45 wiz Exp $
#

DISTNAME=	readline-5.1
PKGNAME=	readline-5.1pl1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

PATCH_SITES=	${MASTER_SITE_GNU:=readline/readline-5.1-patches/}
PATCHFILES=	readline51-001

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

INFO_FILES=		history.info readline.info rluserman.info

.include "../../mk/bsd.pkg.mk"
