# $NetBSD: Makefile,v 1.12 2000/10/28 23:04:31 wiz Exp $

DISTNAME=	dn9a1011
PKGNAME=	darcnes-20001011
WRKSRC=		${WRKDIR}/darcnes
CATEGORIES=	emulators
MASTER_SITES=	http://www.netway.com/~nyef/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.netway.com/~nyef/

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
.endif

.if ( ${MACHINE_ARCH} == "i386" )
MAKE_FLAGS+=	MACH_TYPES=-DMACH_TYPES=\\\"types-i386.h\\\"
.else
MAKE_FLAGS+=	C_ONLY=-DC_ONLY
.endif
