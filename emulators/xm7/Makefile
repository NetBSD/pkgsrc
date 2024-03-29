# $NetBSD: Makefile,v 1.34 2023/07/07 07:34:56 nia Exp $
#

DISTNAME=		xm71020s
PKGNAME=		xm7-1020s
CATEGORIES=		emulators
MASTER_SITES=		http://yohkai.no-ip.info/fm7/
MASTER_SITES+=		http://www.mirrorservice.org/pub/minix/distfiles/backup/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://yohkai.no-ip.info/fm7/XM7.htm
COMMENT=		X11-based FM-7 emulator
LICENSE=		xm7-license

RESTRICTED=		source archive is not redistributable
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

TOOL_DEPENDS+=		nkf>=1.7:../../converters/nkf

NOT_FOR_BULK_PLATFORM=	Linux-*-*

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} == "none"
PKG_SKIP_REASON+=	"Requires an OSS implementation"
.endif

EXTRACT_OPTS_ZIP=	-aqoLL	# lower-case filenames are expected

WRKSRC=			${WRKDIR}/vm
NO_CONFIGURE=		yes
MAKE_FILE=		makefile.x11
INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKDIR} && mv linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
