# $NetBSD: Makefile,v 1.2 2002/08/25 19:22:16 jlam Exp $
#

DISTNAME=		GConf-1.1.10
PKGNAME=		GConf2-1.1.10
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/GConf/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://advogato.org/proj/GConf/
COMMENT=		configuration database system used by GNOME (v2)

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../databases/db3/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../net/ORBit2/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
