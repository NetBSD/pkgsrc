# $NetBSD: Makefile,v 1.2 2004/04/05 05:16:49 xtraeme Exp $
#

DISTNAME=	raines-0.40.0
PKGNAME=	${DISTNAME:S/raines/raine/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.rainemu.com/html/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.rainemu.com/
COMMENT=	680x0 Arcade Emulator

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/raine
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes
MAKEFILE=	makefile
MAKE_ENV+=	OSTYPE=linux
USE_PERL5=	run

ONLY_FOR_PLATFORM=  *-*-i386

pre-install:
	@${SED} -e s,@RAINEDATA@,${PREFIX}/share/raine, \
	    ${FILESDIR}/raine.sh > ${WRKSRC}/raine.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${PREFIX}/bin/raine

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
