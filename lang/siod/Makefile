# $NetBSD: Makefile,v 1.24 2016/02/25 14:42:57 jperkin Exp $

DISTNAME=		siod
PKGNAME=		siod-3.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		# ftp://ftp.std.com/pub/gjc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://people.delphi.com/gjc/siod.html
COMMENT=		Small-footprint implementation of the Scheme programming language

CONFLICTS=		siag-[0-9]*

WRKSRC=			${WRKDIR}
MAKE_FILE=		makefile
MAKE_JOBS_SAFE=		no
BUILD_TARGET=		${OPSYS:S/Linux/linux/}
MAKE_ENV+=		CC=${CC:Q}
CPPFLAGS+=		-Dunix=1

# XXX: cannot check as WRKSRC == WRKDIR so paths are stripped
CHECK_SHLIBS_SUPPORTED=	no

REPLACE_INTERPRETER+=	siod
REPLACE.siod.old=	/usr/local/bin/siod
REPLACE.siod.new=	${PREFIX}/bin/siod
REPLACE_FILES.siod=	*.scm

MAKE_ENV.SunOS+=	CPPFLAGS=

post-patch:
	${MV} ${WRKSRC}/siod.man ${WRKSRC}/prefix-siod.man
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/prefix-siod.man > ${WRKSRC}/siod.man

.include "../../databases/sdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
