# $NetBSD: Makefile,v 1.8 2003/03/29 12:41:32 jmmv Exp $

DISTNAME=		siod
PKGNAME=		siod-3.0
WRKSRC=			${WRKDIR}
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.std.com/pub/gjc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://people.delphi.com/gjc/siod.html
COMMENT=		Small-footprint implementation of the Scheme programming language

DEPENDS+=		sdbm-[0-9]*:../../databases/sdbm

MAKEFILE=		makefile
ALL_TARGET=		${OPSYS}
MAKE_ENV+=		CC="${CC}"
CPPFLAGS+=		-Dunix=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

post-patch:
	${MV} ${WRKSRC}/siod.man ${WRKSRC}/prefix-siod.man
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/prefix-siod.man > ${WRKSRC}/siod.man

.include "../../mk/bsd.pkg.mk"
