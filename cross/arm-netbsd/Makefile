# $NetBSD: Makefile,v 1.1.1.1 1999/12/06 09:38:35 sakamoto Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-arm-netbsd
BINUTILS_LDEMULATION=	armnbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		arm-netbsd

.include "../COMMON/cross.mk"
