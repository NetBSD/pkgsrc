# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 15:56:42 shannonjr Exp $
#

DISTNAME=		prelude-lml-0.9.1
CATEGORIES=		security
MASTER_SITES=		http://www.prelude-ids.org/download/releases/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.prelude-ids.org/download/releases/
COMMENT=		Log analyzer monitoring your logfile and received syslog messages

.include "../../mk/bsd.prefs.mk"

PRELUDE_USER?=          _prelude
PRELUDE_GROUP?=         _prelude

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-fam
CONFIGURE_ARGS+=        --localstatedir=${VARBASE:Q}
RCD_SCRIPTS=		preludelml
PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_HOME=		${VARBASE:Q}/prelude-lml
PKG_USERS=	${PRELUDE_USER}:${PRELUDE_GROUP}::Prelude\ IDS:${PRELUDE_HOME}:${NOLOGIN}
PKG_GROUPS=	${PRELUDE_GROUP}
FILES_SUBST+=	PRELUDE_LML_PID_DIR=${PRELUDE_LML_PID_DIR:Q}
FILES_SUBST+=	PRELUDE_USER=${PRELUDE_USER:Q}

SUBST_CLASSES+=         code
SUBST_STAGE.code=       post-patch
SUBST_FILES.code=       run-prelude-lml.c
SUBST_SED.code=         -e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=        -e 's,@PRELUDE_USER@,${PRELUDE_USER},g'

pre-patch:
	${CP} ${FILESDIR}/run-prelude-lml.c ${WRKSRC}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-lml run-prelude-lml.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-lml ${PREFIX}/sbin/run-prelude-lml
	${CHMOD} 755 ${PKG_SYSCONFDIR}/prelude-lml
	${CHOWN} -R ${PRELUDE_USER}:${PRELUDE_GROUP} ${PRELUDE_HOME}

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
