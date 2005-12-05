# $NetBSD: Makefile,v 1.7 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=	radmind-1.5.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://rsug.itd.umich.edu/software/radmind/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hf@spg.tu-darmstadt.de
HOMEPAGE=	http://rsug.itd.umich.edu/software/radmind/
COMMENT=	Remote file administration and integrity tool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-radminddir=${VARBASE}/radmind
CONFIGURE_ENV+=		diffpath=${TOOLS_DIFF:Q}
USE_TOOLS+=		diff

BUILD_TARGET=	all man rash

USE_PKGINSTALL=	YES
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
