# $NetBSD: Makefile,v 1.18 2006/03/04 21:30:34 jlam Exp $

DISTNAME=	libfwbuilder-2.0.10
PKGREVISION=	4
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder API

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/fwbuilder/libfwbuilder.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/fwcompiler/libfwcompiler.la ${PREFIX}/lib
	${LIBTOOL} --mode=finish ${PREFIX}/lib

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
