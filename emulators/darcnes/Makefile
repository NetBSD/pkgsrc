# $NetBSD: Makefile,v 1.15.2.1 2002/06/23 18:45:30 jlam Exp $

DISTNAME=	dn9b0401
PKGNAME=	darcnes-20010401
WRKSRC=		${WRKDIR}/darcnes
CATEGORIES=	emulators
MASTER_SITES=	http://www.dridus.com/~nyef/darcnes/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.dridus.com/~nyef/darcnes/
COMMENT=	multi-system emulator (NES, SMS, GG, PCE, and others)

LICENSE=	no-commercial-use

USE_X11=	yes
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcnes ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/darcnes
	${INSTALL_MAN} ${WRKSRC}/readme ${PREFIX}/share/doc/darcnes

.include "../../mk/bsd.pkg.mk"

.if ( ${OBJECT_FMT} == "a.out" )
MAKE_FLAGS+=	ASM_FLAGS=-DASM_UNDERBARS
MAKE_FLAGS+=	NO_MULTIPLE_COMMON_WARNING=-DNO_MULTIPLE_COMMON_WARNING
.endif

.if ( ${MACHINE_ARCH} == "i386" )
MAKE_FLAGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.else
MAKE_FLAGS+=	C_ONLY=-DC_ONLY
.endif
