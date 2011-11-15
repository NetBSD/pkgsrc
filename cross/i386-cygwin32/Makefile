# $NetBSD: Makefile,v 1.18 2011/11/15 20:26:04 shattered Exp $
#

DISTVERSION=		1.0.0.0
DISTFILES=		# none
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Cross-compile environment for Cywin32/i386

NOT_FOR_PLATFORM=	*-*-x86_64

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
	${CP} ${FILESDIR}/i386_limits.h ${CROSS_SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${CROSS_SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${CROSS_SYS_INCLUDE}/

.include "../../cross/COMMON/cross.mk"
