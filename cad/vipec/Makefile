# $NetBSD: Makefile,v 1.57 2013/02/16 11:20:30 wiz Exp $
#

DISTNAME=	ViPEC-3.2.0
PKGREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vipec/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vipec.sourceforge.net/
COMMENT=	Network analyser for electrical networks

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES+=	datasize

INSTALLATION_DIRS=	bin
CONFLICTS+=		vipec-[0-9]*

post-patch:
	${SED} 's;@prefix@;${PREFIX};g' < ${FILESDIR}/vipec.sh.in > ${WRKDIR}/vipec.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vipec.sh ${DESTDIR}${PREFIX}/bin/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec.cfg ${DESTDIR}${PREFIX}/vipec
	${RM} -fr ${DESTDIR}${PREFIX}/vipec/*/CVS  ${DESTDIR}${PREFIX}/vipec/help/models/CVS

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
