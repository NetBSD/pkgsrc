# $NetBSD: Makefile,v 1.1 1999/01/06 01:20:28 tv Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-powerpc
BINUTILS_LDEMULATION=	elf32ppc
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		powerpc-netbsd

.include "../COMMON/cross.mk"
