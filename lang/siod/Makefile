# $NetBSD: Makefile,v 1.2 1999/08/06 10:39:30 agc Exp $

DISTNAME=		siod
PKGNAME=		siod-3.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.std.com/pub/gjc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		ftp://ftp.std.com/pub/gjc/siod.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# untested on NetBSD

NO_WRKSUBDIR=		yes
MAKEFILE=		makefile
ALL_TARGET=		${OPSYS}
MAKE_ENV+=		CC=${CC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

post-patch:
	${MV} ${WRKSRC}/siod.man ${WRKSRC}/prefix-siod.man
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/prefix-siod.man > ${WRKSRC}/siod.man

.include "../../mk/bsd.pkg.mk"
