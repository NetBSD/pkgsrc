# $NetBSD: Makefile,v 1.8 2004/04/25 03:48:25 snj Exp $
#

DISTNAME=	xgap4r16
PKGNAME=	xgap-4.16
PKGREVISION=	1
CATEGORIES=	math x11
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/share/
EXTRACT_SUFX=	.zoo

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.gap-system.org/Share/xgap.html
COMMENT=	GUI for GAP

WRKSRC=         ${WRKDIR}/${GAP_PKG_NAME}
USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
ALL_TARGET=	default

CONFIGURE_ENV+=	GAP_DIRECTORY=${GAP_DIRECTORY}

GAP_PKG_NAME=	xgap

post-buildlink:
	(cd ${WRKDIR} && ${LN} -s ${GAP_DIRECTORY}/cnf cnf)

do-install:
	${INSTALL_PROGRAM_DIR} ${GAP_PKG_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${GAP_PLATFORM}/xgap		\
				${GAP_PKG_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xgap.sh				\
				${PREFIX}/bin/xgap
	${INSTALL_DATA} ${WRKSRC}/init.g ${GAP_PKG_DIRECTORY}
	for I in doc examples htm lib; do				\
		cd ${WRKSRC} && ${PAX} -rw $$I ${GAP_PKG_DIRECTORY};	\
		done

.include "../../math/gap/gap.package.mk"
.include "../../mk/bsd.pkg.mk"
