# $NetBSD: Makefile,v 1.53 2022/02/03 23:54:36 wiz Exp $

DISTNAME=		prewikka-${VERSION}
PKGNAME=		${PYPKGPREFIX}-prewikka-${VERSION}
PKGREVISION=		1
CATEGORIES=		security
#MASTER_SITES=		http://www.prelude-ids.org/download/releases/prewikka/
#MASTER_SITES+=		http://www.prelude-ids.org/download/releases/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

VERSION=		0.9.17.1

CONFLICTS=		prewikka-[0-9]*

USE_TOOLS+=		msgfmt

.include "../../mk/bsd.prefs.mk"

REPLACE_PYTHON=	scripts/prewikka-httpd
PYTHON_VERSIONS_ACCEPTED= 27 # py-cheetah

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
SUBST_STAGE.code=	pre-configure
SUBST_FILES.code=	runPrewikka.c
SUBST_VARS.code=	PREFIX
SUBST_VARS.code+=	PREWIKKA_USER
SUBST_VARS.code+=	PYTHONBIN

FILES_SUBST+=	PREWIKKA_USER=${PREWIKKA_USER:Q}

MAKE_ENV+=	EXAMPLEDIR=share/examples/${PKGBASE}

INSTALLATION_DIRS+=	share/examples/${PKGBASE} sbin
CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/prewikka.conf ${PKG_SYSCONFDIR}/prewikka.conf

pre-patch:
	cp ${FILESDIR}/runPrewikka.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${CC} ${CFLAGS} -o runPrewikka runPrewikka.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/runPrewikka ${DESTDIR}${PREFIX}/sbin/runPrewikka

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.9
.include "../../security/libpreludedb-python/buildlink3.mk"
.include "../../security/libprelude-python/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
