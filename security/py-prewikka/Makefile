# $NetBSD: Makefile,v 1.7 2006/05/18 20:30:00 wiz Exp $
#

DISTNAME=		prewikka-0.9.5
CATEGORIES=		security
MASTER_SITES=		http://prelude-ids.org/download/releases/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

BROKEN_IN=		pkgsrc-2006Q1

.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py
REPLACE_PYTHON=		prewikka-httpd
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
FILES_SUBST+=	PREWIKKA_USER=${PREWIKKA_USER:Q}

pre-patch:
		${CP} ${FILESDIR}/runPrewikka.c ${WRKSRC}

post-build:
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o runPrewikka runPrewikka.c

post-install:
		${INSTALL_PROGRAM} ${WRKSRC}/runPrewikka ${PREFIX}/sbin/runPrewikka

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/libpreludedb/buildlink3.mk"
.include "../../security/libprelude/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
