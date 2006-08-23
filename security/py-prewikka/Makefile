# $NetBSD: Makefile,v 1.12 2006/08/23 18:51:56 wiz Exp $
#

DISTNAME=		prewikka-${VERSION}
PKGNAME=		${PYPKGPREFIX}-prewikka-${VERSION}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

VERSION=		0.9.7

CONFLICTS=		prewikka-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py
PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	scripts/prewikka-httpd
PREWIKKA_USER?=		prewikka
PREWIKKA_GROUP?=	prewikka
PREWIKKA_HOME=		/nonexistent
RCD_SCRIPTS=		prewikka

PKG_GROUPS=	${PREWIKKA_GROUP}
PKG_USERS=	${PREWIKKA_USER}:${PREWIKKA_GROUP}

PKG_GECOS.${PREWIKKA_USER}=	Prelude-IDS console
PKG_HOME.${PREWIKKA_USER}=	${PREWIKKA_HOME}

SUBST_CLASSES+=		code
SUBST_STAGE.code=	post-patch
SUBST_FILES.code=	runPrewikka.c
SUBST_SED.code=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=	-e 's,@PREWIKKA_USER@,${PREWIKKA_USER},g'
SUBST_SED.code+=	-e 's,@PYTHONBIN@,${PYTHONBIN},g'
FILES_SUBST+=	PREWIKKA_USER=${PREWIKKA_USER:Q}

pre-patch:
		${CP} ${FILESDIR}/runPrewikka.c ${WRKSRC}

post-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o runPrewikka runPrewikka.c

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/runPrewikka ${PREFIX}/sbin/runPrewikka

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.9
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
