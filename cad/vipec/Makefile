# $NetBSD: Makefile,v 1.48 2006/05/26 18:09:57 dmcmahill Exp $
#

DISTNAME=	ViPEC-3.2.0
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vipec/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vipec.sourceforge.net/
COMMENT=	Network analyser for electrical networks

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES+=	datasize

CONFLICTS+=		vipec-[0-9]*

post-patch:
	${SED} 's;@prefix@;${PREFIX};g' < ${FILESDIR}/vipec.sh.in > ${WRKDIR}/vipec.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vipec.sh ${PREFIX}/bin/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec.cfg ${PREFIX}/vipec
	${RM} -fr ${PREFIX}/vipec/*/CVS  ${PREFIX}/vipec/help/models/CVS

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
