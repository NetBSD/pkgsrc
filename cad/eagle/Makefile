# $NetBSD: Makefile,v 1.26 2015/08/13 20:27:43 tnn Exp $

DISTNAME=		eagle-lin32-7.3.0
PKGREVISION=		1
PKGNAME=		${DISTNAME:S/-lin32//}
CATEGORIES=		cad
MASTER_SITES=		http://web.cadsoft.de/ftp/eagle/program/7.3/
EXTRACT_SUFX=		.run
EXTRACT_CMD=		tail +126 $$extract_file | ${TOOLS_PATH.bsdtar} -C ${WRKDIR} -xjf -

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cadsoft.de/
COMMENT=		Easy to use printed circuit board editor
LICENSE=		eagle-license

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=		bsdtar bzip2 pax
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11 freetype2 fontconfig openssl cups krb5

INSTALLATION_DIRS=	bin eagle

QT_XKB_CONFIG_ROOT=	${X11BASE}/share/X11/xkb

do-build:
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" -e "s:@@QT_XKB_CONFIG_ROOT@@:${QT_XKB_CONFIG_ROOT}:g" <${FILESDIR}/eagle >${WRKDIR}/eagle

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/eagle/.
	${INSTALL_SCRIPT} ${WRKDIR}/eagle ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
