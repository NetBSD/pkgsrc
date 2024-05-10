# $NetBSD: Makefile,v 1.139 2024/05/10 06:52:13 rillig Exp $

PKGNAME=	url2pkg-23.3.1
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/docs/pkgsrc/creating.html
COMMENT=	Tool to automate initial steps in building a package
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run pax
AUTO_MKDIRS=	yes

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-extract:
	${RUN} cd ${FILESDIR} && ${PAX} -rw *.* python/*.py python/*/*.py python/*/*/*.py ${WRKSRC}/

# PY_TEST_FLAGS
#	Can be used to increase the verbosity of the self-test, by passing
#	-v or -vvv.
do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} PKGSRCDIR=${PKGSRCDIR} MAKE=${MAKE:Q} \
		${PREFIX}/bin/pytest-${PYVERSSUFFIX} ${PY_TEST_FLAGS:U}

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
	${RUN} cd ${WRKSRC};						\
	for f in $$(find python -name '*.py' -print); do		\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/lib/url2pkg/"$$f"; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
