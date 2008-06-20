# $NetBSD: Makefile,v 1.11 2008/06/20 01:09:37 joerg Exp $
#

DISTNAME=	bibparse-1.06
CATEGORIES=	textproc
MASTER_SITES=	http://www.math.utah.edu/pub/bibparse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibparse/
COMMENT=	Syntax checking tools for BibTeX bibliography databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=	YES
USE_TOOLS+=	yacc

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
