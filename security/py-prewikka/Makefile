# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 16:00:44 shannonjr Exp $
#

DISTNAME=		prewikka-0.9.3
CATEGORIES=		security
MASTER_SITES=		http://prelude-ids.org/download/releases/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://prelude-ids.org/download/releases/
COMMENT=		Prelude-IDS console

.include "../../mk/bsd.prefs.mk"

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes
PYSETUP=		setup.py
REPLACE_PYTHON=		prewikka-httpd
PREWIKKA_USER?=		prewikka
PREWIKKA_GROUP?=	prewikka
PREWIKKA_HOME=		/nonexistent
RCD_SCRIPTS=		prewikka

PKG_USERS=	${PREWIKKA_USER}:${PREWIKKA_GROUP}::Prelude\-IDS\ console:${PREWIKKA_HOME}:${NOLOGIN}
PKG_GROUPS=	${PREWIKKA_GROUP}

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
