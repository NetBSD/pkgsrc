# $NetBSD: Makefile,v 1.4 2001/11/30 17:33:31 jlam Exp $
#

DISTNAME=	stow-1.3.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.ai.mit.edu/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

INFO_FILES=	stow.info

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
