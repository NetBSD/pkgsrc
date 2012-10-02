# $NetBSD: Makefile,v 1.16 2012/10/02 20:11:42 asau Exp $

DISTNAME=		gprolog-1.3.1
CATEGORIES=		lang
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.gprolog.org/
COMMENT=		GNU prolog compiler and interpreter

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/lib/${PKGNAME_NOREV} \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/gprolog/html \
			--with-examples-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags=${CFLAGS:Q}

# Apparently build failures hang forever if multiple MAKE_JOBS are in use.
MAKE_JOBS_SAFE= 	no

.include "../../mk/bsd.pkg.mk"
