# $NetBSD: Makefile,v 1.2 2001/02/16 14:04:58 wiz Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for a.out NetBSD/i386 (static binaries only)

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-i386-netbsd
BINUTILS_LDEMULATION=	i386nbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsd

.include "../COMMON/cross.mk"
