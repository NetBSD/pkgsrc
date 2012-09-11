# $NetBSD: Makefile,v 1.22 2012/09/11 23:04:35 asau Exp $
#

DISTNAME=	xgap4r16
PKGNAME=	xgap-4.16
PKGREVISION=	3
CATEGORIES=	math x11
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/xgap.html
COMMENT=	GUI for GAP

WRKSRC=		${WRKDIR}/${GAP_PKG_NAME}
GNU_CONFIGURE=	YES
BUILD_TARGET=	default

USE_TOOLS+=	pax

CONFIGURE_ENV+=	GAP_DIRECTORY=${GAP_DIRECTORY:Q}

GAP_PKG_NAME=	xgap

INSTALLATION_DIRS=	bin

pre-configure:
	(cd ${WRKDIR} && ${LN} -s ${GAP_DIRECTORY}/cnf cnf)

do-install:
	${INSTALL_PROGRAM_DIR}						\
		${DESTDIR}${GAP_PKG_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${GAP_PLATFORM}/xgap		\
		${DESTDIR}${GAP_PKG_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xgap.sh				\
		${DESTDIR}${PREFIX}/bin/xgap
	${INSTALL_DATA} ${WRKSRC}/init.g ${DESTDIR}${GAP_PKG_DIRECTORY}
	for I in doc examples htm lib; do				\
		cd ${WRKSRC} &&						\
		pax -rw $$I ${DESTDIR}${GAP_PKG_DIRECTORY};		\
	done

.include "../../math/gap/gap.package.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
