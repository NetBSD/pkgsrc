# $NetBSD: Makefile,v 1.15 2010/01/29 17:07:28 joerg Exp $

DISTNAME=	jdb-1.13
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/JDB/index.html
COMMENT=	Commands for manipulating flat-ASCII databases

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--with-perl=${LOCALBASE}/bin
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/jdb

REPLACE_PERL+=		crl_to_db *.pm dblib.pl

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			LIBDIR=${DESTDIR}${PREFIX}/share/jdb

.include "../../mk/bsd.pkg.mk"
