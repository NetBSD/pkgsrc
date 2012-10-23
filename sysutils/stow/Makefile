# $NetBSD: Makefile,v 1.21 2012/10/23 19:51:24 asau Exp $
#

DISTNAME=	stow-1.3.3
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	perl:run
INFO_FILES=	# PLIST

.include "../../mk/bsd.pkg.mk"
