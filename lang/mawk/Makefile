# $NetBSD: Makefile,v 1.25 2012/10/02 20:11:45 asau Exp $
#

DISTNAME=	mawk-1.3.4-20100625
PKGNAME=	${DISTNAME:S/-20/.20/}
CATEGORIES=	lang
MASTER_SITES=	ftp://invisible-island.net/mawk/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.invisible-island.net/mawk/
COMMENT=	AWK clone by Mike Brennan
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=		yes

TEST_TARGET=		mawk_test fpe_test
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
