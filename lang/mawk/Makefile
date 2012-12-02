# $NetBSD: Makefile,v 1.27 2012/12/02 10:28:41 cheusov Exp $
#

DISTNAME=	mawk-1.3.4-20121129
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
