# $NetBSD: Makefile,v 1.25 2022/11/23 16:20:53 adam Exp $

DISTNAME=	openconnect-9.01
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	https://www.infradead.org/openconnect/download/ \
		ftp://ftp.infradead.org/pub/openconnect/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/
COMMENT=	Open source VPN client
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config bash

DEPENDS+=	vpnc-script-[0-9]*:../../net/vpnc-script

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-vpnc-script=${PKG_SYSCONFDIR}/vpnc-script
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-docs

REPLACE_PYTHON=		trojans/*.py
REPLACE_BASH=		trojans/*.sh

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
