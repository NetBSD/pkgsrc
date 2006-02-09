# $NetBSD: Makefile,v 1.20 2006/02/09 22:38:12 heinz Exp $
#

DISTNAME=	tnef-1.3.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tnef/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://tnef.sourceforge.net/
COMMENT=	Decode MS-TNEF MIME attachments

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
TEST_TARGET=		check

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnef
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
