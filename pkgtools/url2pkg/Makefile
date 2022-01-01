# $NetBSD: Makefile,v 1.122 2022/01/01 14:04:11 rillig Exp $

PKGNAME=	url2pkg-21.4.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/creating.html
COMMENT=	Tool to automate initial steps in building a package
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
AUTO_MKDIRS=	yes

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-extract:
	${RUN} cd ${FILESDIR} && cp *.* ${WRKSRC}/

do-test:
	${RUN} cd ${WRKSRC} && env PKGSRCDIR=${PKGSRCDIR} MAKE=${MAKE:Q} \
		${PREFIX}/bin/pytest-${PYVERSSUFFIX} ${PY_TEST_FLAGS:U}

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		up
SUBST_STAGE.up=		do-configure
SUBST_MESSAGE.up=	Replacing variable placeholders
SUBST_FILES.up=		MakeMaker.pm url2pkg.py
SUBST_VARS.up=		MAKE PERL5 PKGSRCDIR PYTHONBIN
SUBST_SED.up=		-e 's,@LIBDIR@,${PREFIX}/lib/url2pkg,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg.py ${DESTDIR}${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/Build.pm ${DESTDIR}${PREFIX}/lib/url2pkg/Module/
	${INSTALL_DATA} ${WRKSRC}/MakeMaker.pm ${DESTDIR}${PREFIX}/lib/url2pkg/ExtUtils/
	${INSTALL_DATA} ${WRKSRC}/setuptools.py ${DESTDIR}${PREFIX}/lib/url2pkg/
	${INSTALL_DATA} /dev/null ${DESTDIR}${PREFIX}/lib/url2pkg/distutils/__init__.py
	${INSTALL_DATA} ${WRKSRC}/setuptools.py ${DESTDIR}${PREFIX}/lib/url2pkg/distutils/core.py
	${INSTALL_DATA} ${WRKSRC}/setuptools.py ${DESTDIR}${PREFIX}/lib/url2pkg/distutils/extension.py

.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
