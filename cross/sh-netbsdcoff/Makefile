# $NetBSD: Makefile,v 1.1.1.1 2001/01/04 01:20:48 itojun Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	coff-sh
BINUTILS_LDEMULATION=	shunx
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		sh-netbsdcoff

.include "../COMMON/cross.mk"
