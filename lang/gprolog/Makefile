# $NetBSD: Makefile,v 1.3 2001/02/17 09:07:10 agc Exp $
#

DISTNAME=		gprolog-1.1.6
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/contraintes/gnu-prolog/unstable/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://gnu-prolog.inria.fr/
COMMENT=		GNU prolog compiler and interpreter

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/libexec/gprolog-1.1.6 \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/html/gprolog \
			--with-example-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags='-O3 -finline-functions -fomit-frame-pointer -D__unix__=1'

WRKSRC=			${WRKDIR}/${DISTNAME}/src

.include "../../mk/bsd.pkg.mk"
