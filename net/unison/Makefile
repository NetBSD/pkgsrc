# $NetBSD: Makefile,v 1.2 2001/02/03 09:07:21 dmcmahill Exp $
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
MAKE_FLAGS+=	CFLAGS="" UISTYLE=text

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} != "i386")
# we don't have ocamlopt on non-i386 so don't try and use it
MAKE_FLAGS+=	NATIVE=false
.endif

.include "../../mk/bsd.pkg.mk"
