# $NetBSD: Makefile,v 1.10 2004/03/28 22:23:25 dmcmahill Exp $
#

DISTNAME=	latex-mk-1.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net/
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES

INFO_FILES=	latex-mk.info

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
