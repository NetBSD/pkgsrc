# $NetBSD: Makefile,v 1.2.2.1 2002/06/23 18:43:07 jlam Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for NetBSD/mipsel

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-littlemips
BINUTILS_LDEMULATION=	elf32lmip
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		mipsel-netbsd

.include "../../mk/bsd.prefs.mk"
.if (${MACHINE_ARCH} == sparc) 
.include "../../lang/gcc/Makefile.gcc"
.endif

.include "../COMMON/cross.mk"
