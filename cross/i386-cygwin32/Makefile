# $NetBSD: Makefile,v 1.1 2000/05/31 17:54:25 oki Exp $
#

DISTVERSION=		1.0.0.0
DISTFILES=		# none

#MAINTAINER=		packages@netbsd.org
#HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-cygwin32

BINUTILS_EXTRAS=	dlltool windres

.include "../COMMON/cross.mk"
