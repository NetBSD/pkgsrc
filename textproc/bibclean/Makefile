# $NetBSD: Makefile,v 1.14 2012/10/25 06:55:42 asau Exp $
#

DISTNAME=	bibclean-2.11.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/tex/bib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibclean/
COMMENT=	Prettyprinter and syntax checker for BibTeX bibliography databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	share/doc/bibclean

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bibclean.dvi ${DESTDIR}${PREFIX}/share/doc/bibclean/

.include "../../mk/bsd.pkg.mk"
