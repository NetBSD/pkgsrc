# $NetBSD: Makefile,v 1.7 2002/08/21 07:20:14 grant Exp $
#

DISTNAME=       cucipop-1.31
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/cucipop/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	cucipop-1.31-v6-20010223.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org
COMMENT=	The Cubic Circle POP3 mail server

LICENSE=	shareware

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

# to be friendly with pre-1.5 systems
.if defined(USE_INET6) && ${USE_INET6} == "YES"
MAKE_ENV+=	CFLAGS_INET6=-DINET6
.endif

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lnsl -lsocket
.endif

post-patch:
	@(cd ${WRKSRC};							\
	for f in config.h cucipop.8 makevpopdb.8; do			\
		${SED} -e 's|@prefix@|${PREFIX}|g' $$f > $$f.fixed &&	\
		${MV} $$f.fixed $$f;					\
	done)

.include "../../mk/bsd.pkg.mk"
