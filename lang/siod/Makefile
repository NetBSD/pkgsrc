# $NetBSD: Makefile,v 1.1.1.1 1999/08/06 09:43:30 agc Exp $

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

.include "../../mk/bsd.pkg.mk"
