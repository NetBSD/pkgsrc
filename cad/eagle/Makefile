# $NetBSD: Makefile,v 1.29 2016/06/05 09:16:33 mef Exp $

DISTNAME=		eagle-lin32-7.6.0
PKGNAME=		${DISTNAME:S/-lin32//}
CATEGORIES=		cad
# Strip microversion from directory name
MASTER_SITES=		http://web.cadsoft.de/ftp/eagle/program/${PKGVERSION_NOREV:C/([0-9]+\.[0-9]+)\.[0-9]/\1/}/
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
	# Drop executable bit for regular files
	${CHMOD} -x ${DESTDIR}${PREFIX}/eagle/projects/examples/seeed/DESCRIPTION
	${CHMOD} -x ${DESTDIR}${PREFIX}/eagle/projects/examples/seeed/*/*
	${CHMOD} -x ${DESTDIR}${PREFIX}/eagle/lbr/seeed/*

.include "../../mk/bsd.pkg.mk"
