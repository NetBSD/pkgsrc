# $NetBSD: Makefile,v 1.10 2006/06/20 22:22:54 minskim Exp $
#

DISTNAME=	bibparse-1.06
CATEGORIES=	textproc
MASTER_SITES=	http://www.math.utah.edu/pub/bibparse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibparse/
COMMENT=	Syntax checking tools for BibTeX bibliography databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	yacc

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
