# $NetBSD: Makefile,v 1.5 2004/11/20 22:10:23 jmmv Exp $

DISTNAME=	libfwbuilder-1.0.2
PKGREVISION=	4
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder API

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../devel/glib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
