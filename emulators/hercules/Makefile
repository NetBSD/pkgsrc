# $NetBSD: Makefile,v 1.28 2012/10/03 12:55:14 asau Exp $

DISTNAME=		hercules-3.07
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.hercules-390.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hercules-390.org/
COMMENT=		S370 emulator
LICENSE=		qpl-v1.0

DEPENDS+=		hercules-images-[0-9]*:../../emulators/hercules-images

AUTOCONF_REQD=		2.50
USE_TOOLS+=		autoconf gmake bash:run
GNU_CONFIGURE=		YES
#MAKE_ENV+=		HOST_ARCH=${MACHINE_ARCH:Q}
USE_LIBTOOL=		YES

PTHREAD_OPTS+=		require

REPLACE_PERL+=		util/cvslvlck
USE_TOOLS+=		perl:run

INSTALLATION_DIRS+=	bin share/examples/hercules
#CONFIGURE_ARGS+=	--enable-setuid-hercifc=hercules
#SPECIAL_PERMS+=		${PREFIX}/bin/hercifc ${SETUID_ROOT_PERMS}

pre-configure:
	${RM} ${WRKSRC}/ltdl.h ${WRKSRC}/ltdl.c
	cd ${WRKSRC} && autoconf
pre-install:
	${INSTALL_DATA} ${WRKSRC}/hercules.cnf ${DESTDIR}${PREFIX}/share/examples/hercules/
#	${INSTALL_DATA} ${WRKSRC}/zzsa.cnf ${DESTDIR}${PREFIX}/share/examples/hercules/

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
