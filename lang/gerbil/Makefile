# $NetBSD: Makefile,v 1.1 2026/10/09 14:31:31 ktnb Exp $

DISTNAME=	gerbil-0.18.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=mighty-gerbils/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/mighty-gerbils/gerbil/
COMMENT=	Dialect of Scheme for systems programming
LICENSE=	apache-2.0 AND gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/${DISTNAME}

CHECK_PORTABILITY_SKIP=		src/gambit/prebuilt/*/*
CHECK_PORTABILITY_SKIP+=	src/gambit/contrib/*/*
CHECK_PORTABILITY_SKIP+=	src/gambit/misc/*

CHECK_INTERPRETER_SKIP+=	${DESTDIR}/${PREFIX}/gerbil/src/std/web/rack-test.ss
CHECK_INTERPRETER_SKIP+=	${DESTDIR}/${PREFIX}/gerbil/src/std/web/fastcgi-test.ss

RELRO_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

REPLACE_INTERPRETER+=	env
REPLACE.env.old=	/usr/bin/env
REPLACE.env.new=	${PREFIX}/gerbil/bin/gxi
REPLACE_FILES.env=	src/std/web/fastcgi-test.ss
REPLACE_FILES.env+=	src/std/web/rack-test.ss

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--version-string=v${PKGVERSION_NOREV}
GNU_CONFIGURE_PREFIX=	${PREFIX}/gerbil
CONFIGURE_ENV=		GERBIL_VERSION=v${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin

GERBIL_BINS=	gerbil gxc gxensemble gxhttpd gxi gxpkg gxprof gxtags gxtest

post-install:
.for b in ${GERBIL_BINS}
	${LN} -sf ${DESTDIR}${PREFIX}/gerbil/bin/${b} ${DESTDIR}${PREFIX}/bin/${b}
.endfor

do-test:
	cd ${WRKSRC}/src/std && ${SETENV} ${TEST_ENV} PATH=${WRKSRC}/build/bin:/usr/bin:/bin gerbil test ./...

.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
