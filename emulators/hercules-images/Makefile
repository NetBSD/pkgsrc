# $NetBSD: Makefile,v 1.5 2003/04/10 20:10:16 grant Exp $

DISTNAME=		mftr33
PKGNAME=		hercules-images-20010222
WRKSRC=			${WRKDIR}
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		Images to IPL the Hercules emulator

NO_BUILD=		yes
NO_CONFIGURE=		yes
EXTRACT_ONLY=

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/data/hercules
	cd ${PREFIX}/share/data/hercules &&				\
		(${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; dd if=/dev/zero bs=10k count=2) | ${PAX} -O -r

.include "../../mk/bsd.pkg.mk"
