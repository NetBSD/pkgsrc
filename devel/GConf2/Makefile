# $NetBSD: Makefile,v 1.4 2002/09/10 16:06:37 wiz Exp $
#

DISTNAME=		GConf-1.2.1
PKGNAME=		${DISTNAME:S/GConf/GConf2/}
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/GConf/}
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
