# $NetBSD: Makefile,v 1.13 2014/10/09 14:07:01 wiz Exp $
#

DISTNAME=	bibparse-1.06
CATEGORIES=	textproc
MASTER_SITES=	http://www.math.utah.edu/pub/bibparse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibparse/
COMMENT=	Syntax checking tools for BibTeX bibliography databases

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=	YES
USE_TOOLS+=	yacc

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
