# $NetBSD: Makefile,v 1.2 2001/02/16 14:05:07 wiz Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for 32-bit ELF NetBSD/sparc

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-sparc
BINUTILS_LDEMULATION=	elf32_sparc
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		sparc-netbsdelf

.include "../COMMON/cross.mk"
