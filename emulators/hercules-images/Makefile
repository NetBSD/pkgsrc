# $NetBSD: Makefile,v 1.8 2004/01/20 12:14:41 agc Exp $

DISTNAME=		mftr33
PKGNAME=		hercules-images-20010222
CATEGORIES=		emulators
MASTER_SITES=		http://www.conmicro.cx/hercules/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.conmicro.cx/hercules/
COMMENT=		Images to IPL the Hercules emulator

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CONFIGURE=		yes
EXTRACT_ONLY=

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/data/hercules
	cd ${PREFIX}/share/data/hercules &&				\
		(${GZCAT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; dd if=/dev/zero bs=10k count=2) | ${PAX} -O -r

.include "../../mk/bsd.pkg.mk"
