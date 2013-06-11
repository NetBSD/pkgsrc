# $NetBSD: Makefile,v 1.18 2013/06/11 20:05:37 asau Exp $

DISTNAME=		gprolog-1.4.4
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

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
