# $NetBSD: Makefile,v 1.1 2017/02/13 18:33:24 fhajny Exp $

DISTNAME=	librelp-1.2.12
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.librelp.com/
COMMENT=	Reliable Event Logging Protocol core library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	relp.pc.in

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
