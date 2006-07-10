# $NetBSD: Makefile,v 1.18 2006/07/10 11:09:24 dmcmahill Exp $
#

DISTNAME=	latex-mk-1.8
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net/
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	awk echo env false find grep gzcat gzip rm rmdir tar

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	BMAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ENV+=	GZCAT=${GZCAT:Q}
CONFIGURE_ENV+=	GZIP=${GZIP_CMD:Q}

INFO_FILES=	# PLIST

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
