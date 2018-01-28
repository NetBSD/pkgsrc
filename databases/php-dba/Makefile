# $NetBSD: Makefile,v 1.17 2018/01/28 20:10:45 wiz Exp $

MODNAME=		dba
CATEGORIES+=		databases
COMMENT=		PHP extension for DBM database access
PKGREVISION=		1

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
