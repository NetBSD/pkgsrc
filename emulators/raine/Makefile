# $NetBSD: Makefile,v 1.4 2004/06/05 17:14:14 xtraeme Exp $
#

DISTNAME=	raines-0.40.2
PKGNAME=	${DISTNAME:S/raines/raine/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.rainemu.com/html/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
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
REPLACE_PERL=	makedep

# XXX Really?
ONLY_FOR_PLATFORM=  *-*-i386

pre-install:
	@(								\
	${ECHO_MSG} "#!/bin/sh";					\
	${ECHO_MSG} "cd ${PREFIX}/share/raine && ./raine"		\
	) > ${WRKSRC}/raine.sh
	@${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${PREFIX}/bin/raine

.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
