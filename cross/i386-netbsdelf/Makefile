# $NetBSD: Makefile,v 1.2 2001/02/16 14:04:59 wiz Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for ELF NetBSD/i386

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-i386
BINUTILS_LDEMULATION=	elf_i386
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdelf

.include "../COMMON/cross.mk"
