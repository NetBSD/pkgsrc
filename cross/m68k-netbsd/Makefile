# $NetBSD: Makefile,v 1.5 2003/07/17 21:27:58 grant Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Cross-compile environment for a.out NetBSD/m68k (static binaries only)

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-m68k-netbsd
BINUTILS_LDEMULATION=	m68knbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		m68k-netbsd

MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../COMMON/cross.mk"
