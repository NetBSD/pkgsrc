# $NetBSD: Makefile,v 1.2 2001/02/16 14:04:52 wiz Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for NetBSD/arm32 (static binaries only)

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-arm-netbsd
BINUTILS_LDEMULATION=	armnbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		arm-netbsd

.include "../COMMON/cross.mk"
