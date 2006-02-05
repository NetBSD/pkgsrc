# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:02 joerg Exp $
#

DISTNAME=	raines-0.40.2
PKGNAME=	${DISTNAME:S/raines/raine/}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.rainemu.com/html/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.rainemu.com/
COMMENT=	680x0 Arcade Emulator

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/raine
USE_TOOLS+=	gmake perl:run
MAKEFILE=	makefile
MAKE_ENV+=	OSTYPE=linux
REPLACE_PERL=	makedep
PTHREAD_OPTS+=	require

# XXX Really?
ONLY_FOR_PLATFORM=  *-*-i386

post-build:
	@(							\
	${ECHO} "#!${SH}";					\
	${ECHO} "cd ${PREFIX}/share/raine && ./raine $$@"	\
	) > ${WRKSRC}/raine.sh

pre-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${PREFIX}/bin/raine

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
