# $NetBSD: Makefile,v 1.68 2012/12/16 01:52:20 obache Exp $
#

DISTNAME=	evolution-exchange-2.32.2
EE_VER=		2.32
PKGREVISION=	15
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-exchange/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.novell.com/products/desktop/features/evolution.html
COMMENT=	Support for Microsoft Exchange 2000 and 2003 in Evolution
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PLIST_SUBST=		EE_VER=${EE_VER:Q}
GCONF_SCHEMAS=		apps_exchange_addressbook-${EE_VER}.schemas

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution+= evolution>=2.32.2
.include "../../mail/evolution/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
