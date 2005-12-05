# $NetBSD: Makefile,v 1.14 2005/12/05 20:50:27 rillig Exp $

DISTNAME=		siod
PKGNAME=		siod-3.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.std.com/pub/gjc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://people.delphi.com/gjc/siod.html
COMMENT=		Small-footprint implementation of the Scheme programming language

WRKSRC=			${WRKDIR}
MAKEFILE=		makefile
BUILD_TARGET=		${OPSYS}
MAKE_ENV+=		CC=${CC:Q}
CPPFLAGS+=		-Dunix=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

post-patch:
	${MV} ${WRKSRC}/siod.man ${WRKSRC}/prefix-siod.man
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/prefix-siod.man > ${WRKSRC}/siod.man

.include "../../databases/sdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
