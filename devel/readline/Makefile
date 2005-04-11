# $NetBSD: Makefile,v 1.35 2005/04/11 21:45:38 tv Exp $
#

DISTNAME=	readline-5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

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
