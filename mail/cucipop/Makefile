# $NetBSD: Makefile,v 1.11 2003/07/17 21:45:48 grant Exp $
#

DISTNAME=       cucipop-1.31
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	The Cubic Circle POP3 mail server

LICENSE=	shareware

BUILD_DEFS+=	USE_INET6

MAKE_ENV+=	ROOT_USER="${ROOT_USER}"
MAKE_ENV+=	ROOT_GROUP="${ROOT_GROUP}"

.include "../../mk/bsd.prefs.mk"

# to be friendly with pre-1.5 systems
.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

pre-configure:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

.include "../../mk/bsd.pkg.mk"
