# $NetBSD: Makefile,v 1.6 2005/02/24 10:59:56 bad Exp $

DISTNAME=	libfwbuilder-2.0.5
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

QMAKE=		${QTDIR}/bin/qmake
CONFIGURE_ENV+=	QMAKE="${QMAKE}"
MAKE_ENV+=	QMAKE="${QMAKE}"

post-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/fwbuilder/libfwbuilder.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/src/fwcompiler/libfwcompiler.la ${PREFIX}/lib
	${LIBTOOL} --mode=finish ${PREFIX}/lib

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
