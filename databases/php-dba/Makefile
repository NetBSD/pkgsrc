# $NetBSD: Makefile,v 1.13 2011/08/23 13:06:48 obache Exp $

MODNAME=		dba
PKGREVISION=		1
CATEGORIES+=		databases
COMMENT=		PHP extension for DBM database access

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-dba-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

CONFIGURE_ARGS+=	--with-cdb
CONFIGURE_ARGS+=	--without-dbm
CONFIGURE_ARGS+=	--with-inifile

.if exists(/usr/include/ndbm.h)
CONFIGURE_ARGS+=	--with-ndbm=/usr
.else
CONFIGURE_ARGS+=	--without-ndbm
.endif

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
