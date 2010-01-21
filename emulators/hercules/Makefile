# $NetBSD: Makefile,v 1.22.24.1 2010/01/21 11:59:30 tron Exp $

DISTNAME=		hercules-2.11
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		http://www.hercules-390.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hercules-390.org/
COMMENT=		S370 emulator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		hercules-images-[0-9]*:../../emulators/hercules-images

USE_TOOLS+=		gmake bash:run
MAKE_FILE=		makefile
MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH:Q}

REPLACE_BASH+=		dasdlist

PTHREAD_OPTS+=		require

INSTALLATION_DIRS+=	bin share/examples/hercules
SPECIAL_PERMS+=		${PREFIX}/bin/hercifc ${SETUID_ROOT_PERMS}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${DESTDIR}${PREFIX}/share/examples/hercules/
	${INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${DESTDIR}${PREFIX}/share/examples/hercules/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
