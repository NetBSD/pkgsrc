# $NetBSD: Makefile,v 1.1.1.1 1999/01/06 03:43:04 tv Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf64-sparc
BINUTILS_LDEMULATION=	elf64_sparc
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		sparc64-netbsd

.include "../COMMON/cross.mk"
