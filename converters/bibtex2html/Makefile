# $NetBSD: Makefile,v 1.1.1.1 2004/03/07 05:40:21 minskim Exp $

DISTNAME=	bibtex2html-1.65
CATEGORIES=	converters
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/bibtex2html/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/bibtex2html/
COMMENT=	Collection of tools for translating from BibTeX to HTML

BUILD_DEPENDS=	ocaml-[0-9]*:../../lang/ocaml

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	run

CONFIGURE_ENV+=	PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
