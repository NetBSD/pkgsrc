# $NetBSD: Makefile,v 1.13 2023/12/30 20:10:13 zafer Exp $

DISTNAME=		mftr33
PKGNAME=		hercules-images-20010222
CATEGORIES=		emulators
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		Images to IPL the Hercules emulator

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CONFIGURE=		yes
EXTRACT_ONLY=
USE_TOOLS+=		gzcat pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/data/hercules
	cd ${DESTDIR}${PREFIX}/share/data/hercules &&			\
		(gzcat ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX};		\
		 dd if=/dev/zero bs=10k count=2) | pax -O -r

.include "../../mk/bsd.pkg.mk"
