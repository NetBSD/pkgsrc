# $NetBSD: Makefile,v 1.1.1.1 1999/02/03 13:00:43 tv Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	elf32-sparc
BINUTILS_LDEMULATION=	elf32_sparc
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		sparc-netbsdelf

.include "../COMMON/cross.mk"
