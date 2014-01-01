# $NetBSD: Makefile,v 1.14 2014/01/01 11:52:34 wiz Exp $
#

DISTNAME=	prelude-pflogger-0.9.0-rc2
PKGNAME=	prelude-pflogger-0.9.0
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	http://prelude-ids.org/download/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prelude-ids.org/download/releases/
COMMENT=	Prelude sensor for Packet Filter (pf)

.include "../../mk/bsd.prefs.mk"

PRELUDE_USER?=		_prelude
PRELUDE_GROUP?=		_prelude
PRELUDE_PFLOGGER_PID_DIR=	${VARBASE}/run/prelude-pflogger

PKG_GROUPS_VARS+=	PRELUDE_GROUP
PKG_USERS_VARS+=	PRELUDE_USER

EGDIR=			${PREFIX}/share/examples/prelude-pflogger
REQD_DIRS=		${EGDIR} ${PKG_SYSCONFDIR}

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	prelude-pflogger
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONF_FILES=		${EGDIR}/prelude-pflogger.conf ${PKG_SYSCONFDIR}/prelude-pflogger.conf
USE_TOOLS+=		autoconf automake aclocal autoheader

FILES_SUBST+=	PRELUDE_PFLOGGER_PID_DIR=${PRELUDE_PFLOGGER_PID_DIR:Q}
FILES_SUBST+=	PRELUDE_USER=${PRELUDE_USER:Q}
FILES_SUBST+=	PRELUDE_GROUP=${PRELUDE_GROUP:Q}

MESSAGE_SUBST+=	PRELUDE_USER=${PRELUDE_USER:Q}
MESSAGE_SUBST+=	PRELUDE_GROUP=${PRELUDE_GROUP:Q}

SUBST_CLASSES+=		code
SUBST_STAGE.code=	post-patch
SUBST_FILES.code=	run-prelude-pflogger.c
SUBST_SED.code=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.code+=	-e 's,@PRELUDE_USER@,${PRELUDE_USER},g'

SUBST_CLASSES+=         make
SUBST_STAGE.make=       post-patch
SUBST_FILES.make=       Makefile.am
SUBST_SED.make=         -e 's,@EGDIR@,${EGDIR},g'

RCD_SCRIPTS=		pflogger

INSTALLATION_DIRS=	share/examples/prelude-pflogger sbin

pre-patch:
	${CP} ${FILESDIR}/run-prelude-pflogger.c ${WRKSRC}

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf
	${LN} -s ${BUILDLINK_DIR}/lib/libltdl.so ${BUILDLINK_DIR}/lib/libltdlc.so

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${CC} ${CFLAGS} -o run-prelude-pflogger run-prelude-pflogger.c

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run-prelude-pflogger ${DESTDIR}${PREFIX}/sbin/run-prelude-pflogger

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
