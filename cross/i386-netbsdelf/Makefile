# $NetBSD: Makefile,v 1.1.1.1 1999/02/14 10:06:08 mrg Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-i386
BINUTILS_LDEMULATION=	elf_i386
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdelf

.include "../COMMON/cross.mk"
