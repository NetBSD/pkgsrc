# $NetBSD: Makefile,v 1.34 2004/12/03 15:14:55 wiz Exp $
#

DISTNAME=	readline-5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool

INFO_FILES=		history.info readline.info rluserman.info

.include "../../mk/bsd.pkg.mk"
