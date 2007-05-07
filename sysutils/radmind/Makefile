# $NetBSD: Makefile,v 1.13 2007/05/07 14:14:06 hauke Exp $
#

DISTNAME=	radmind-1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=radmind/}

MAINTAINER=	hf@spg.tu-darmstadt.de
HOMEPAGE=	http://rsug.itd.umich.edu/software/radmind/
COMMENT=	Remote file administration and integrity tool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-radminddir=${RADMINDDIR}
CONFIGURE_ENV+=		diffpath=${TOOLS_DIFF:Q}
USE_TOOLS+=		diff

BUILD_TARGET=		all man rash
RADMINDDIR=		${VARBASE}/radmind
BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${RADMINDDIR} ${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/client ${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/preapply ${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/postapply ${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/cert ${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=		radmind

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
