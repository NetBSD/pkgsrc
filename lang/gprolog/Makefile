# $NetBSD: Makefile,v 1.9 2004/04/28 05:06:28 snj Exp $

DISTNAME=		gprolog-1.2.16
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.inria.fr/INRIA/Projects/contraintes/gprolog/

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://gnu-prolog.inria.fr/
COMMENT=		GNU prolog compiler and interpreter

ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc *-*-sparc

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/libexec/${PKGNAME} \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/html/gprolog \
			--with-examples-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags='-O3 -finline-functions -fomit-frame-pointer -D__unix__=1'

.include "../../mk/bsd.pkg.mk"
