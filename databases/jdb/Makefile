# $NetBSD: Makefile,v 1.17 2012/10/03 21:54:12 wiz Exp $

DISTNAME=	jdb-1.13
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

REPLACE_PERL+=		crl_to_db *.pm dblib.pl

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			LIBDIR=${DESTDIR}${PREFIX}/share/jdb

.include "../../mk/bsd.pkg.mk"
