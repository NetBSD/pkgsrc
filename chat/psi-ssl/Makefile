# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:15 tv Exp $

DISTNAME=	qssl-2.0
PKGNAME=	psi-ssl-2.0
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORCE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client - SSL plugin

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11=	yes

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake qssl.pro
	$(SED) 's:\(-module.*\):\1 $(QTDIR)/lib:' ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new && ${MV} ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC} && libtool --mode=install ${INSTALL_PROGRAM} libqssl.la ${QTDIR}/lib

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
