# $NetBSD: Makefile,v 1.1.1.1 1999/12/06 09:34:28 sakamoto Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${BINUTILS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	a.out-i386-netbsd
BINUTILS_LDEMULATION=	i386nbsd
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsd

.include "../COMMON/cross.mk"
