# $NetBSD: Makefile,v 1.4 2000/11/06 05:40:28 minoura Exp $
#

DISTVERSION=		1.0.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-cygwin32

BINUTILS_EXTRAS=	dlltool windres

## XXX
## These headers are required to build libgcc.
## We have to use the Cygwin versions of the headers, but for now
## these are enough.
## Actually we have to install Cygwin headers and libraries with this package;
## the header files from NetBSD should be deleted at that time.
post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${SYS_INCLUDE}/

.include "../COMMON/cross.mk"
