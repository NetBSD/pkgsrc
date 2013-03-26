# $NetBSD: Makefile,v 1.32 2013/03/26 14:38:11 hauke Exp $
#

DISTNAME=	radmind-1.14.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=radmind/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://rsug.itd.umich.edu/software/radmind/
COMMENT=	Remote file administration and integrity tool
LICENSE=	modified-bsd

# Not yet 64 bit time_t safe, see PR pkg/46555
NOT_FOR_PLATFORM=      NetBSD-5.99.*-* NetBSD-[6-9]*-*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-radminddir=${RADMINDDIR}
CONFIGURE_ENV+=		diffpath=${TOOLS_DIFF:Q}
# XXX configure script checks for path to echo, which pkgsrc does not
# provide, so we need to side-step {echopath}.
CONFIGURE_ENV+= 	ac_cv_path_echopath=${TOOLS_ECHO:Q}

BUILD_TARGET=		all man rash
RADMINDDIR=		${VARBASE}/radmind
BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${RADMINDDIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/client ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/preapply ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/postapply ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0750
OWN_DIRS_PERMS+=	${RADMINDDIR}/cert ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
RCD_SCRIPTS=		radmind

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
