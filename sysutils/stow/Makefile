# $NetBSD: Makefile,v 1.13 2004/01/20 02:18:50 jlam Exp $
#

DISTNAME=	stow-1.3.3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.ai.mit.edu/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

INFO_FILES=	stow.info

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
