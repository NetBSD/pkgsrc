# $NetBSD: Makefile,v 1.27 2013/03/02 10:44:37 tron Exp $
#

DISTNAME=	tnef-1.4.3
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tnef/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
