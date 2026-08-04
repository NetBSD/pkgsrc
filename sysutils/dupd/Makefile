# $NetBSD: Makefile,v 1.4 2026/08/04 20:29:15 wiz Exp $

DISTNAME=	dupd-1.7.3
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jvirkki/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://www.virkki.com/dupd/
COMMENT=	File duplicate detection CLI utility
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake bash perl

USE_LANGUAGES=	c

MAKE_ENV+=	MANBASE=${PREFIX}/${PKGMANDIR}
BUILD_TARGET=	dupd
TEST_TARGET=	test

REPLACE_BASH=	tests/test.??

DOCDIR=		share/doc/dupd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dupd ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dupd.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for mdfile in CONTRIBUTING design examples index performance
	${INSTALL_DATA} ${WRKSRC}/docs/${mdfile}.md \
		${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
