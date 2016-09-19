# $NetBSD: Makefile,v 1.5 2016/09/19 13:04:28 wiz Exp $
#

DISTNAME=	iksemel-1.4
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://iksemel.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/iksemel/
COMMENT=	XML parser library mainly designed for Jabber applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	iksemel.pc.in

.include "../../mk/bsd.prefs.mk"

.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
