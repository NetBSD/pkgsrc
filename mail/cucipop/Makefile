# $NetBSD: Makefile,v 1.15 2004/11/15 15:13:12 jlam Exp $
#

DISTNAME=	cucipop-1.31
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	The Cubic Circle POP3 mail server

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

LICENSE=	shareware

BUILD_DEFS+=	USE_INET6

MAKE_ENV+=	ROOT_USER="${ROOT_USER}"
MAKE_ENV+=	ROOT_GROUP="${ROOT_GROUP}"

MAKE_DIRS+=	${PREFIX}/share/cucipop/bulletins
SPECIAL_PERMS+=	${PREFIX}/sbin/cucipop ${ROOT_USER} ${ROOT_GROUP} 2755

PKG_OPTIONS_VAR=	PKG_OPTIONS.cucipop
PKG_SUPPORTED_OPTIONS=	db

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb)
.  include "../../mk/bdb.buildlink3.mk"
BDB_ACCEPTED=	db2
CFLAGS+=	-DUSE_DB
MAKE_ENV+=	LIBS=${BUILDLINK_LIBS.bdb}
.endif

# to be friendly with pre-1.5 systems
.if defined(USE_INET6) && (${USE_INET6} == "YES")
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

LDFLAGS.SunOS+=	-lnsl -lsocket

pre-configure:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cucipop ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/makevpopdb ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/cucipop.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/makevpopdb.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
