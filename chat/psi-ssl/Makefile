# $NetBSD: Makefile,v 1.2 2003/08/05 13:36:05 drochner Exp $

PKGNAME=	psi-ssl-2.0
DISTNAME=	qssl-2.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/psi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi.affinix.com/
COMMENT=	PSI Jabber Client - SSL plugin

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake qssl.pro
	$(SED) 's:\(-module.*\):\1 $(QTDIR)/lib:' ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.new && mv ${WRKSRC}/Makefile.new ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC} && libtool --mode=install ${INSTALL_PROGRAM} libqssl.la ${QTDIR}/lib

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
