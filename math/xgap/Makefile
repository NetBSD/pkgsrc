# $NetBSD: Makefile,v 1.26 2025/05/06 18:22:11 bsiegert Exp $

DISTNAME=	xgap-4.32
CATEGORIES=	math x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gap-packages/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gap-system.org/Packages/xgap.html
COMMENT=	GUI for GAP

#WRKSRC=		${WRKDIR}/${GAP_PKG_NAME}
GNU_CONFIGURE=	YES
BUILD_TARGET=	default

USE_TOOLS+=	pax

CONFIGURE_ARGS+=	--with-gaproot=${GAP_DIRECTORY:Q}

GAP_PKG_NAME=	xgap

REPLACE_PERL+=		doc/buildman.pe
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
