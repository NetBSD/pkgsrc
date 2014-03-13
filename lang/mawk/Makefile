# $NetBSD: Makefile,v 1.29 2014/03/13 16:35:23 adam Exp $

DISTNAME=	mawk-1.3.4-20131226
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

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
