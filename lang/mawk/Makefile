# $NetBSD: Makefile,v 1.31 2016/02/25 14:42:56 jperkin Exp $

DISTNAME=	mawk-1.3.4-20150503
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.invisible-island.net/mawk/
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1

TEST_TARGET=		mawk_test fpe_test

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

MAKE_ENV.SunOS+=	CPPFLAGS=

.include "../../mk/bsd.pkg.mk"
