# $NetBSD: Makefile,v 1.40 2023/12/30 20:16:40 wiz Exp $

DISTNAME=	raines-0.43.3
PKGNAME=	${DISTNAME:S/raines/raine/}
PKGREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://raine.1emulation.com/
COMMENT=	680x0 Arcade Emulator

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake perl:run pkg-config
MAKE_FILE=	makefile
MAKE_ENV+=	OSTYPE=linux
REPLACE_PERL=	makedep
PTHREAD_OPTS+=	require

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

# Uses i386 assembler.
ONLY_FOR_PLATFORM=	*-*-i386

post-build:
	(${ECHO} "#!${SH}";					\
	 ${ECHO} "cd ${PREFIX}/share/raine && ./raine $$@")	\
		> ${WRKSRC}/raine.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/raine ${DESTDIR}${PREFIX}/share/raine
	${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${DESTDIR}${PREFIX}/bin/raine

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
