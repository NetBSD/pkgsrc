# $NetBSD: Makefile,v 1.5 2003/04/21 21:46:58 jschauma Exp $
#

DISTNAME=	bibclean-2.11.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.math.utah.edu/pub/tex/bib/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://www.math.utah.edu/pub/bibclean/
COMMENT=	prettyprinter and syntax checker for BibTeX bibliography databases

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bibclean
	${INSTALL_DATA} ${WRKSRC}/doc/bibclean.dvi ${PREFIX}/share/doc/bibclean/

.include "../../mk/bsd.pkg.mk"
