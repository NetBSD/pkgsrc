# $NetBSD: Makefile,v 1.6 2003/06/23 19:48:19 jtb Exp $
#

DISTNAME=		gprolog-1.2.16
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/contraintes/gprolog/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://gnu-prolog.inria.fr/
COMMENT=		GNU prolog compiler and interpreter

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc *-*-powerpc

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/libexec/${PKGNAME} \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/html/gprolog \
			--with-examples-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags='-O3 -finline-functions -fomit-frame-pointer -D__unix__=1'

.include "../../mk/bsd.pkg.mk"
