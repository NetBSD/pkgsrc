# $NetBSD: Makefile,v 1.10 2003/08/05 20:38:13 seb Exp $
#

DISTNAME=	stow-1.3.3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.ai.mit.edu/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

USE_NEW_TEXINFO=	YES
INFO_FILES=	stow.info

.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
