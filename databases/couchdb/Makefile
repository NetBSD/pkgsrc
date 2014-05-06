# $NetBSD: Makefile,v 1.26 2014/05/06 13:50:13 fhajny Exp $
#

DISTNAME=		apache-couchdb-1.5.1
PKGNAME=		${DISTNAME:S/apache-//}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_APACHE:=couchdb/source/${PKGVERSION_NOREV}/}

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://couchdb.apache.org/
COMMENT=		Document database server, accessible via a RESTful JSON API
LICENSE=		apache-2.0

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
INFO_FILES=		yes
BUILD_DEFS+=		VARBASE

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "../../mk/bsd.prefs.mk"

COUCH_DBDIR?=		${VARBASE}/db/couchdb
COUCH_EGDIR=		${PREFIX}/share/examples/couchdb
COUCH_LOGDIR?=		${VARBASE}/log/couchdb
COUCH_USER?=		couchdb
COUCH_GROUP?=		${COUCH_USER}

PKG_GROUPS+=		${COUCH_GROUP}
PKG_USERS+=		${COUCH_USER}:${COUCH_GROUP}
PKG_GECOS.${COUCH_USER}=CouchDB Server User
PKG_HOME.${COUCH_USER}=	${COUCH_DBDIR}
PKG_SHELL.${COUCH_USER}=${COMMAND_SHELL}

# Solaris /var/run is root only
.if ${OPSYS} == "SunOS"
COUCH_RUNDIR?=		${VARBASE}/spool/couchdb
.else
COUCH_RUNDIR?=		${VARBASE}/run/couchdb
.endif

FILES_SUBST+=		COUCH_USER=${COUCH_USER}
FILES_SUBST+=		COUCH_GROUP=${COUCH_GROUP}
FILES_SUBST+=		COUCH_DBDIR=${COUCH_DBDIR}

OWN_DIRS=		${COUCH_LOGDIR} ${COUCH_DBDIR} ${COUCH_RUNDIR} ${PKG_SYSCONFDIR}
OWN_DIRS_PERMS+=	${COUCH_DBDIR} ${COUCH_USER} ${COUCH_GROUP} 0770
OWN_DIRS_PERMS+=	${COUCH_LOGDIR} ${COUCH_USER} ${COUCH_GROUP} 0770
OWN_DIRS_PERMS+=	${COUCH_RUNDIR} ${COUCH_USER} ${COUCH_GROUP} 0770

PKG_SYSCONFSUBDIR=	couchdb
PKG_SYSCONFDIR_PERMS=	${COUCH_USER} ${COUCH_GROUP} 0775
CONF_FILES_PERMS+=	${COUCH_EGDIR}/default.ini ${PKG_SYSCONFDIR}/default.ini ${COUCH_USER} ${COUCH_GROUP} 0660
CONF_FILES_PERMS+=	${COUCH_EGDIR}/local.ini ${PKG_SYSCONFDIR}/local.ini ${COUCH_USER} ${COUCH_GROUP} 0660

CONFIGURE_ARGS+=	--disable-init
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-erlang=${BUILDLINK_PREFIX.erlang}/lib/erlang/usr/include
CONFIGURE_ARGS+=	--with-js-include=${BUILDLINK_PREFIX.spidermonkey}
CONFIGURE_ARGS+=	--with-js-lib=${BUILDLINK_PREFIX.spidermonkey}

.if ${OPSYS} == "SunOS"
REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		/bin/sh
REPLACE.sh.new=		/bin/ksh
REPLACE_FILES.sh=	bin/couchdb.tpl.in
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	configure bin/couchdb.tpl.in
SUBST_VARS.paths=	COUCH_EGDIR COUCH_DBDIR COUCH_LOGDIR COUCH_RUNDIR
SUBST_SED.paths=	-e 's,@ERLANG_PREFIX@,${BUILDLINK_PREFIX.erlang},g'

# This works around libtool abuse installing "couchspawnkillable". Will
# hopefully get fixed properly upstream.
SUBST_CLASSES+=		unstrip
SUBST_MESSAGE.unstrip=	Avoiding trying to strip a shell script
SUBST_STAGE.unstrip=	post-configure
SUBST_FILES.unstrip+=	src/couchdb/priv/Makefile
SUBST_SED.unstrip=	-e '/^INSTALL_PROGRAM =/s, -s,,'

PLIST_SUBST+=		VERSION.ejson=${VERSION.ejson}
PLIST_SUBST+=		VERSION.ibrowse=${VERSION.ibrowse}
PLIST_SUBST+=		VERSION.mochiweb=${VERSION.mochiweb}
PLIST_SUBST+=		VERSION.snappy=${VERSION.snappy}

.include "Makefile.versions"

.include "../../lang/erlang/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
