# $NetBSD: Makefile,v 1.4 2001/03/31 11:14:30 zuntum Exp $

DISTNAME=		siod
PKGNAME=		siod-3.0
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.std.com/pub/gjc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		ftp://ftp.std.com/pub/gjc/siod.html
COMMENT=		Small-footprint implementation of the Scheme programming language

ONLY_FOR_PLATFORM=	SunOS-*-*	# untested on NetBSD

NO_WRKSUBDIR=		yes
MAKEFILE=		makefile
ALL_TARGET=		${OPSYS}
MAKE_ENV+=		CC="${CC}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

post-patch:
	${MV} ${WRKSRC}/siod.man ${WRKSRC}/prefix-siod.man
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/prefix-siod.man > ${WRKSRC}/siod.man

.include "../../mk/bsd.pkg.mk"
