# $NetBSD: Makefile,v 1.54 2011/11/01 06:00:45 sbd Exp $
#

DISTNAME=	ViPEC-3.2.0
PKGREVISION=	9
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vipec/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vipec.sourceforge.net/
COMMENT=	Network analyser for electrical networks

PKG_DESTDIR_SUPPORT=	user-destdir

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
