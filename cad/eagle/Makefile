# $NetBSD: Makefile,v 1.25 2015/08/12 17:39:36 tnn Exp $

DISTNAME=		eagle-lin64-7.3.0
PKGNAME=		${DISTNAME:S/-lin64//}
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
EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	x11 freetype2 fontconfig openssl cups krb5

INSTALLATION_DIRS=	bin eagle

do-build:
	${SED} -e "s:@@PREFIX@@:${PREFIX}:g" <${FILESDIR}/eagle >${WRKDIR}/eagle

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/eagle/.
	${INSTALL_SCRIPT} ${WRKDIR}/eagle ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
