# $NetBSD: Makefile,v 1.3 2000/12/01 21:08:03 fredb Exp $
#

DISTNAME=       cucipop-1.31
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cucipop-1.31-v6-20001122.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org

LICENSE=	shareware

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

# to be friendly with pre-1.5 systems
.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

post-patch:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

.include "../../mk/bsd.pkg.mk"
