# $NetBSD: Makefile,v 1.36 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	ViPEC-3.1.3
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vipec/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vipec.sourceforge.net/
COMMENT=	Network analyser for electrical networks

BUILD_DEPENDS+=		tmake-*:../../devel/tmake

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
UNLIMIT_RESOURCES+=	datasize

CONFLICTS+=		vipec-[0-9]*

ALL_TARGET=		ALL

do-configure:
	cd ${WRKSRC}/src && tmake vipec "CONFIG+=release" -o Makefile
	#cd ${WRKSRC}/src && tmake vipec "CONFIG+=debug" -o Makefile

post-patch:
	${SED} 's;@prefix@;${PREFIX};g' < ${FILESDIR}/vipec.sh.in > ${WRKDIR}/vipec.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vipec.sh ${PREFIX}/bin/vipec
	${INSTALL_DATA} ${WRKSRC}/vipec.cfg ${PREFIX}/vipec

.include "../../x11/qt2-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
