# $NetBSD: Makefile,v 1.1.1.1 2001/01/11 01:45:36 mjl Exp $
#

DISTNAME=	src
PKGNAME=	unison-2.6.11
CATEGORIES=	net
MASTER_SITES=	http://www.cis.upenn.edu/~bcpierce/unison/download/stable/latest/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cis.upenn.edu/~bcpierce/unison/

BUILD_DEPENDS=	ocamlc:../../lang/ocaml

DIST_SUBDIR=	unison

# docs: unison-manual.pdf/html/ps/dvi
WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes
MAKE_FLAGS=	CFLAGS="" UISTYLE=text

.include "../../mk/bsd.pkg.mk"
