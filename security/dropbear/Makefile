# $NetBSD: Makefile,v 1.18 2006/03/14 20:03:43 drochner Exp $

DISTNAME=	dropbear-0.48.1
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	SSH2 server, aimed at embedded market

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

PKG_OPTIONS_VAR=	PKG_OPTIONS.dropbear
PKG_SUPPORTED_OPTIONS=	pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-pam
.endif

MAKEFLAGS+=	ROOT_USER=${ROOT_USER:Q} ROOT_GROUP=${ROOT_GROUP:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dropbear
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dropbear

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
