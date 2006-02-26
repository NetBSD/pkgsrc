# $NetBSD: Makefile,v 1.11 2006/02/26 13:50:14 schwarz Exp $
#

DISTNAME=	bibclean-2.11.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/tex/bib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibclean/
COMMENT=	Prettyprinter and syntax checker for BibTeX bibliography databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bibclean
	${INSTALL_DATA} ${WRKSRC}/doc/bibclean.dvi ${PREFIX}/share/doc/bibclean/

.include "../../mk/bsd.pkg.mk"
