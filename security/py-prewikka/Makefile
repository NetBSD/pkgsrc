# $NetBSD: Makefile,v 1.40 2014/05/09 07:37:18 wiz Exp $

DISTNAME=		prewikka-${VERSION}
PKGNAME=		${PYPKGPREFIX}-prewikka-${VERSION}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/prewikka/ \
			http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

VERSION=		0.9.17.1

CONFLICTS=		prewikka-[0-9]*

USE_TOOLS+=		msgfmt

.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=		yes
PYSETUP=		setup.py
REPLACE_PYTHON=	scripts/prewikka-httpd
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-cheetah

PREWIKKA_USER?=		prewikka
PREWIKKA_GROUP?=	prewikka
PREWIKKA_HOME=		/nonexistent
RCD_SCRIPTS=		prewikka
PKG_SYSCONFSUBDIR=	prewikka

PKG_GROUPS=	${PREWIKKA_GROUP}
PKG_USERS=	${PREWIKKA_USER}:${PREWIKKA_GROUP}

PKG_GECOS.${PREWIKKA_USER}=	Prelude-IDS console
PKG_HOME.${PREWIKKA_USER}=	${PREWIKKA_HOME}

PKG_GROUPS_VARS+=	PREWIKKA_GROUP
PKG_USERS_VARS+=	PREWIKKA_USER

SUBST_CLASSES+=		code
SUBST_STAGE.code=	post-patch
SUBST_FILES.code=	runPrewikka.c
SUBST_SED.code=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=	-e 's,@PREWIKKA_USER@,${PREWIKKA_USER},g'
SUBST_SED.code+=	-e 's,@PYTHONBIN@,${PYTHONBIN},g'

FILES_SUBST+=	PREWIKKA_USER=${PREWIKKA_USER:Q}

MAKE_ENV+=	EXAMPLEDIR=share/examples/${PKGBASE}

INSTALLATION_DIRS+=	share/examples/${PKGBASE} sbin
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/prewikka.conf ${PKG_SYSCONFDIR}/prewikka.conf

pre-patch:
	cp ${FILESDIR}/runPrewikka.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${CC} ${CFLAGS} -o runPrewikka runPrewikka.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/runPrewikka ${DESTDIR}${PREFIX}/sbin/runPrewikka

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.9
.include "../../security/libpreludedb-python/buildlink3.mk"
.include "../../security/libprelude-python/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
