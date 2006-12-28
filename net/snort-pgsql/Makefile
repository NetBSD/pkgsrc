# $NetBSD: Makefile,v 1.22 2006/12/28 12:12:58 joerg Exp $

.include "../../net/snort/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-pgsql-/}
PKGREVISION=	1

COMMENT=	Network Intrusion Detection System (with PostgreSQL support)

CONFLICTS+=	snort-[0-9]*
CONFLICTS+=	snort-mysql-[0-9]*

PKGDIR=		${.CURDIR}/../../net/snort
FILESDIR=	${PKGDIR}/files
PATCHDIR=	${PKGDIR}/patches
DISTINFO_FILE=	${PKGDIR}/distinfo

CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX:Q}

PKG_OPTIONS_VAR=        PKG_OPTIONS.snort-pgsql
PKG_SUPPORTED_OPTIONS=  debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.endif

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
