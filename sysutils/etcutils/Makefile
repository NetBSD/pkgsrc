# $NetBSD: Makefile,v 1.2 2010/07/01 18:08:38 joerg Exp $
#

DISTNAME=	etcutils-0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jmmv/etcutils/0.1/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~jmmv/etcutils/
COMMENT=	Utilities to programmatically edit configuration files
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=/etc SH=${SH}

PKG_OPTIONS_VAR=	PKG_OPTIONS.etcutils
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
CONFIGURE_ARGS+=	--with-atf
DEPENDS+=		atf-[0-9]*:../../devel/atf
PLIST_SUBST+=		TESTS=
.else
CONFIGURE_ARGS+=	--without-atf
PLIST_SUBST+=		TESTS="@comment"
.endif

.include "../../mk/bsd.pkg.mk"
