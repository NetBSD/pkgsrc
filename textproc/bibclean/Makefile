# $NetBSD: Makefile,v 1.7 2004/03/07 06:33:40 minskim Exp $
#

DISTNAME=	bibclean-2.11.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/tex/bib/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibclean/
COMMENT=	Prettyprinter and syntax checker for BibTeX bibliography databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bibclean
	${INSTALL_DATA} ${WRKSRC}/doc/bibclean.dvi ${PREFIX}/share/doc/bibclean/

.include "../../mk/bsd.pkg.mk"
