# $NetBSD: Makefile,v 1.11 2006/07/17 17:59:43 wiz Exp $
#

DISTNAME=	radmind-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=radmind/}

MAINTAINER=	hf@spg.tu-darmstadt.de
HOMEPAGE=	http://rsug.itd.umich.edu/software/radmind/
COMMENT=	Remote file administration and integrity tool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-radminddir=${VARBASE}/radmind
CONFIGURE_ENV+=		diffpath=${TOOLS_DIFF:Q}
USE_TOOLS+=		diff

BUILD_TARGET=	all man rash

OWN_DIRS_PERMS+=        ${VARBASE}/radmind \
			        ${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=        ${VARBASE}/radmind/client \
				${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=        ${VARBASE}/radmind/preapply \
				${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=        ${VARBASE}/radmind/postapply \
				${ROOT_USER} ${ROOT_GROUP} 0750
OWN_DIRS_PERMS+=        ${VARBASE}/radmind/cert \
				${ROOT_USER} ${ROOT_GROUP} 0700
RCD_SCRIPTS=	radmind

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
