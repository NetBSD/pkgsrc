# $NetBSD: Makefile,v 1.15 2020/06/02 08:24:34 adam Exp $

DISTNAME=	openconnect-8.05
PKGREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.infradead.org/pub/openconnect/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/
COMMENT=	Client for Cisco AnyConnect VPN
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config bash

DEPENDS+=	vpnc-script-[0-9]*:../../net/vpnc-script

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-vpnc-script=${PKG_SYSCONFDIR}/vpnc-script
CONFIGURE_ARGS+=	--disable-nls

REPLACE_PYTHON=		trojans/tncc-wrapper.py
REPLACE_BASH=		trojans/*.sh

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS=	sbin include lib ${PKGMANDIR}/man8

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
