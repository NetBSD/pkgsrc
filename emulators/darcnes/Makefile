# $NetBSD: Makefile,v 1.3 2000/02/14 02:44:31 wiz Exp $

DISTNAME=	dn9a0212
PKGNAME=	darcnes-20000212
WRKSRC=		${WRKDIR}/darcnes
CATEGORIES=	emulators
MASTER_SITES=	http://www.netway.com/~nyef/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.netway.com/~nyef/

USE_X11=	yes
USE_GMAKE=	yes

# make dependencies
post-patch:
	cd ${WRKSRC} && ${GMAKE}

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
