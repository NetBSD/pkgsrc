# $NetBSD: Makefile,v 1.1.1.1 2001/01/04 01:21:09 itojun Exp $
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

TARGET_ARCH=		shel-netbsdcoff

.include "../COMMON/cross.mk"
