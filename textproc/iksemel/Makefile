# $NetBSD: Makefile,v 1.7 2017/08/16 21:22:14 wiz Exp $

DISTNAME=	iksemel-1.4
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://iksemel.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/meduketto/iksemel
COMMENT=	XML parser library mainly designed for Jabber applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	iksemel.pc.in

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
