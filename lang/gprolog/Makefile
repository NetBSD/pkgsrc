# $NetBSD: Makefile,v 1.1.1.1 2000/07/03 10:27:49 agc Exp $
#

DISTNAME=		gprolog-1.1.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/contraintes/gnu-prolog/unstable/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://gnu-prolog.inria.fr/

#ONLY_FOR_PLATFORM=	NetBSD-*-i386

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/libexec/gprolog-1.1.6 \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/html/gprolog \
			--with-example-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags='-O3 -finline-functions -fomit-frame-pointer -D__unix__=1'

WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
