# $NetBSD: Makefile,v 1.22 2010/12/31 21:55:50 dmcmahill Exp $
#

DISTNAME=	latex-mk-2.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex-mk/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://latex-mk.sourceforge.net/
COMMENT=	Makefile fragments and scripts for managing LaTeX documents

LICENSE=	original-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	awk echo env false find grep gzcat gzip makeinfo rm rmdir tar

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	BMAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ENV+=	GZCAT=${GZCAT:Q}
CONFIGURE_ENV+=	GZIP=${GZIP_CMD:Q}

INFO_FILES=	yes

TEST_DIRS=	${WRKSRC}
TEST_TARGET=	check

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
