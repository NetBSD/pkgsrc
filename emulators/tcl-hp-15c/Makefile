# $NetBSD: Makefile,v 1.1 2018/08/31 09:24:25 hauke Exp $

DISTNAME=	HP-15C_4.0.00_Source
PKGNAME=	tcl-hp-15c-${PKGVER}
PKGVER=		4.0.00.5811
CATEGORIES=	emulators math
MASTER_SITES=	-http://bit.ly/2FQ82VL
EXTRACT_SUFX=	.zip

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://hp-15c.homepage.t-online.de/
COMMENT=	Simulated HP-15C RPN calculator
LICENSE=	gnu-gpl-v3

DEPENDS+=       tk>=8.3.2:../../x11/tk

NO_CONFIGURE=   YES
NO_BUILD=       YES

USE_TOOLS+=     unzip pax find sed

HP15CDIR=	share/tcl-hp-15c

INSTALLATION_DIRS=	share/fonts/X11/TTF
INSTALLATION_DIRS+=	${HP15CDIR}
INSTALLATION_DIRS+=	bin

FONTS_DIRS.ttf= 	${PREFIX}/share/fonts/X11/TTF

do-extract:
	${MKDIR} ${WRKSRC} ; \
	cd ${WRKSRC} ; \
	${UNZIP_CMD} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-extract:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/hp-15c.sh > ${WRKDIR}/hp-15c.sh

do-install:
	${FIND} ${WRKSRC} -type f -exec chmod -x \{\} \;
	cd ${WRKSRC} ; ${PAX} -rw . ${DESTDIR}${PREFIX}/${HP15CDIR}
	${INSTALL_DATA} ${WRKSRC}/HP-15C_Simulator_Font.ttf \
		${DESTDIR}${FONTS_DIRS.ttf}/HP-15C_Simulator_Font.ttf
	${INSTALL_SCRIPT} ${WRKDIR}/hp-15c.sh ${DESTDIR}${PREFIX}/bin/hp-15c

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
