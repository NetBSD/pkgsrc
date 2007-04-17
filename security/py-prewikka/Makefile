# $NetBSD: Makefile,v 1.19 2007/04/17 13:15:08 joerg Exp $
#

DISTNAME=		prewikka-${VERSION}
PKGNAME=		${PYPKGPREFIX}-prewikka-${VERSION}
#PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/ \
			http://www.prelude-ids.org/download/releases/old/

VERSION=		0.9.10

CONFLICTS=		prewikka-[0-9]*

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

USE_TOOLS+=		msgfmt

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
PKG_SYSCONFSUBDIR=	prewikka

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

MAKE_ENV+=	EXAMPLEDIR=share/examples/${PKGBASE}

INSTALLATION_DIRS+=	${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/prewikka.conf ${PKG_SYSCONFDIR}/prewikka.conf

pre-patch:
	cp ${FILESDIR}/runPrewikka.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${CC} ${CFLAGS} -o runPrewikka runPrewikka.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/runPrewikka ${PREFIX}/sbin/runPrewikka

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.9
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
