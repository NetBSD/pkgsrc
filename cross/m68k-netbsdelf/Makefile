# $NetBSD: Makefile,v 1.3 2001/05/27 15:17:37 dmcmahill Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for ELF NetBSD/m68k

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-m68k
BINUTILS_LDEMULATION=	m68kelfnbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		m68k-netbsdelf

MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

.include "../COMMON/cross.mk"
