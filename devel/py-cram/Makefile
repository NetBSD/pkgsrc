# $NetBSD: Makefile,v 1.1 2024/11/12 15:45:45 riastradh Exp $

DISTNAME=	cram-0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cram/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/cram/
COMMENT=	Simple testing framework for command line applications
LICENSE=	gnu-gpl-v2

post-install:
	cd ${DESTDIR:Q}${PREFIX:Q}/bin && ${MV} cram cram-${PYVERSSUFFIX}

TEST_DEPENDS+=	bash>=0:../../shells/bash
TEST_DEPENDS+=	patch>=0:../../devel/patch	# expects GNU patch(1) output

# /bin/bash is referenced via command line arguments and strings, not
# in `#!' interpreter lines, so use SUBST instead of REPLACE_BASH.
SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_MESSAGE.bash=	Fixing /bin/bash references
SUBST_FILES.bash+=	tests/setup.sh
SUBST_FILES.bash+=	tests/test.t
SUBST_SED.bash+=	-e 's,/bin/bash,'${PREFIX:Q}'/bin/bash,g'

do-test:
	@${STEP_MSG} Running cram tests
	${RUN}cd ${WRKSRC:Q} && \
		${SETENV} ${TEST_ENV} \
			PYTHON=${PYTHONBIN:Q} \
			PYTHONPATH="$$(pwd)" \
			PATH=${PREFIX:Q}/gnu/bin:"$$PATH" \
		${PYTHONBIN:Q} scripts/cram tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
