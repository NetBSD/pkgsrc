# $NetBSD: Makefile,v 1.13 2010/05/19 09:10:55 asau Exp $

DISTNAME=		gprolog-1.3.1
CATEGORIES=		lang
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		brook@nmsu.edu
HOMEPAGE=		http://www.gprolog.org/
COMMENT=		GNU prolog compiler and interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src
CONFIGURE_ARGS+=	--with-install-dir=${PREFIX}/lib/${PKGNAME_NOREV} \
			--with-doc-dir=${PREFIX}/share/doc/gprolog \
			--with-html-dir=${PREFIX}/share/doc/gprolog/html \
			--with-examples-dir=${PREFIX}/share/examples/gprolog \
			--with-c-flags=${CFLAGS:Q}

.include "../../mk/bsd.pkg.mk"
