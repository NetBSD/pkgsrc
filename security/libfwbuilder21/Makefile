# $NetBSD: Makefile,v 1.1.1.1 2006/11/09 19:06:37 bad Exp $

DISTNAME=	libfwbuilder-2.1.7
PKGNAME=	libfwbuilder21-2.1.7
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder API

CONFLICTS=	libfwbuilder-[0-9]*

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb5
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
