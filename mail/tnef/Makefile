# $NetBSD: Makefile,v 1.34 2020/03/20 11:58:00 nia Exp $

DISTNAME=	tnef-1.4.18
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=verdammelt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tnef.sourceforge.net/
COMMENT=	Decode MS-TNEF MIME attachments
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake autoreconf
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnef
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
