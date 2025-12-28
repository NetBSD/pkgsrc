# $NetBSD: Makefile,v 1.20 2025/12/28 15:13:53 adam Exp $

DISTNAME=	kea-3.1.4
COMMENT=	Next-generation ISC Dynamic Host Configuration Protocol (DHCP) Server

.include "options.mk"

CATEGORIES=	net
MASTER_SITES=	https://ftp.isc.org/isc/kea/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.isc.org/kea/
LICENSE=	mpl-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	VARBASE
MAKE_DIRS+=	${VARBASE}/lib/kea
MAKE_DIRS+=	${VARBASE}/run/kea
MESON_ARGS+=	-Drunstatedir=${VARBASE}
PY_PATCHPLIST=	yes
RCD_SCRIPTS=	kea

.if ${USE_CROSS_COMPILE:tl} == "yes"
# This appears to store an absolute path to the bison(1) executable
# which lives in TOOLBASE (or possibly in TOOLS_DIR).
CHECK_WRKREF_SKIP+=	lib/libkea-process*
.endif

INSTALLATION_DIRS+=	share/examples/kea

post-install:
	${RM} -fr ${DESTDIR}${PREFIX}/share/examples/kea && \
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/kea \
                ${DESTDIR}${PREFIX}/share/examples/kea

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
