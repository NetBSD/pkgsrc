# $NetBSD: Makefile,v 1.28 2013/05/13 01:47:57 wen Exp $
#

DISTNAME=	mawk-1.3.4-20130219
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

.include "../../mk/bsd.prefs.mk"

# mawk configure fails with -ffast-math
CFLAGS:=	${CFLAGS:S/-ffast-math//}

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

DOCDIR=			${PREFIX}/share/doc/mawk
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} README CHANGES ${DESTDIR}${DOCDIR}/

.include "../../mk/bsd.pkg.mk"
