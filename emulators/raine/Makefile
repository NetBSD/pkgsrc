# $NetBSD: Makefile,v 1.15 2006/09/09 02:42:00 obache Exp $
#

DISTNAME=	raines-0.43.3
PKGNAME=	${DISTNAME:S/raines/raine/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.rainemu.com/html/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rainemu.com/
COMMENT=	680x0 Arcade Emulator

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake perl:run pkg-config
MAKE_FILE=	makefile
MAKE_ENV+=	OSTYPE=linux
REPLACE_PERL=	makedep
PTHREAD_OPTS+=	require

USE_DIRS+=	xdg-1.1

# XXX Really?
ONLY_FOR_PLATFORM=  *-*-i386

post-build:
	(${ECHO} "#!${SH}";					\
	 ${ECHO} "cd ${PREFIX}/share/raine && ./raine $$@")	\
		> ${WRKSRC}/raine.sh

post-install:
	${MV} ${PREFIX}/bin/raine ${PREFIX}/share/raine
	${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${PREFIX}/bin/raine

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
