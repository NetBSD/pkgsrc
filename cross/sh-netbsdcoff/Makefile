# $NetBSD: Makefile,v 1.3 2001/02/16 14:05:05 wiz Exp $
#

DISTVERSION=		1.3.0.0
DISTFILES=		# none

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		Cross-compile environment for big-endian NetBSD/{mmeye,evbsh3}

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	coff-sh
BINUTILS_LDEMULATION=	shunx
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes
EGCS_MULTILIB=		yes

TARGET_ARCH=		sh-netbsdcoff

.include "../COMMON/cross.mk"
