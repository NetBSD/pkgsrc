# $NetBSD: Makefile,v 1.15 2005/07/16 19:10:40 jlam Exp $
#

DISTNAME=	stow-1.3.3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.ai.mit.edu/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	perl:run

INFO_FILES=	stow.info

.include "../../mk/bsd.pkg.mk"
