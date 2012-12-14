# $NetBSD: Makefile,v 1.17 2012/12/14 14:42:53 wiz Exp $

DISTNAME=		gprolog-1.4.2
CATEGORIES=		lang
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.gprolog.org/
COMMENT=		GNU prolog compiler and interpreter
LICENSE=		gnu-lgpl-v3 OR gnu-gpl-v2

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
