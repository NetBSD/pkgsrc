# $NetBSD: Makefile,v 1.13.2.1 2005/12/17 23:44:25 salo Exp $

DISTNAME=	dropbear-0.46
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
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

MAKEFLAGS+=	ROOT_USER=${ROOT_USER} ROOT_GROUP=${ROOT_GROUP}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dropbear
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dropbear

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
