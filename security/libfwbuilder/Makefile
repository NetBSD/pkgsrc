# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 18:04:39 agc Exp $

DISTNAME=	libfwbuilder-1.0.2
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
