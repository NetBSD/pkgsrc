# $NetBSD: Makefile,v 1.2 2001/02/16 14:05:02 wiz Exp $
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

.include "../COMMON/cross.mk"
