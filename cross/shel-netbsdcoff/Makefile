# $NetBSD: Makefile,v 1.2 2001/01/09 13:24:47 itojun Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	coff-shl
BINUTILS_LDEMULATION=	shlunx
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes
EGCS_MULTILIB=		yes

TARGET_ARCH=		shel-netbsdcoff

.include "../COMMON/cross.mk"
