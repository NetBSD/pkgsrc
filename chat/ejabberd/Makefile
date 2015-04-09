# $NetBSD: Makefile,v 1.51 2015/04/09 06:35:53 fhajny Exp $

DISTNAME=	ejabberd-15.03
CATEGORIES=	chat
MASTER_SITES=	http://www.process-one.net/downloads/ejabberd/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

DISTFILES=	${DEFAULT_DISTFILES} ${DISTNAME}-deps.tar.gz
SITES.${DISTNAME}-deps.tar.gz=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/fhajny/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		git-base>=1.5:../../devel/git-base
CONFLICTS+=		jabberd-[0-9]*

GNU_CONFIGURE=		yes
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake patch

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--enable-iconv
CONFIGURE_ARGS+=	--enable-json
CONFIGURE_ARGS+=	--enable-lager
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--enable-nif
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-pgsql
CONFIGURE_ARGS+=	--enable-zlib

CONFIGURE_ARGS+=	--enable-user=${EJABBERD_USER}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

RCD_SCRIPTS=		ejabberd

BUILD_DEFS+=		EJABBERD_USER EJABBERD_GROUP EJABBERD_LOGDIR
BUILD_DEFS+=		EJABBERD_PIDDIR EJABBERD_DB EJABBERD_TRANSDIR
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	ejabberd

.include "../../mk/bsd.prefs.mk"

EJABBERD_USER?=		ejabberd
EJABBERD_GROUP?=	ejabberd
EJABBERD_PIDDIR?=	${VARBASE}/run/ejabberd
EJABBERD_LOGDIR?=	${VARBASE}/log/ejabberd
EJABBERD_DB?=		${VARBASE}/spool/ejabberd

OWN_DIRS_PERMS+=	${EJABBERD_PIDDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_LOGDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_DB} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770

FILES_SUBST+=		DISTNAME=${DISTNAME}
FILES_SUBST+=		EJABBERD_USER=${EJABBERD_USER}
FILES_SUBST+=		EJABBERD_GROUP=${EJABBERD_GROUP}
FILES_SUBST+=		EJABBERD_DB=${EJABBERD_DB}

PLIST_SUBST+=		DISTNAME=${DISTNAME}
PLIST_SUBST+=		EJABBERD_EXDIR=${EJABBERD_EXDIR}

PKG_GROUPS+=		${EJABBERD_GROUP}
PKG_USERS+=		${EJABBERD_USER}:${EJABBERD_GROUP}
PKG_GECOS.${EJABBERD_USER}=	ejabberd user
PKG_HOME.${EJABBERD_USER}=	${EJABBERD_DB}
PKG_SHELL.${EJABBERD_USER}=	${SH}

EGDIR=			share/examples/ejabberd

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES_PERMS=	${EGDIR}/ejabberd.yml ${PKG_SYSCONFDIR}/ejabberd.yml \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/ejabberdctl.cfg ${PKG_SYSCONFDIR}/ejabberdctl.cfg \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/inetrc ${PKG_SYSCONFDIR}/inetrc \
			${ROOT_USER} ${EJABBERD_GROUP} 0640
SPECIAL_PERMS+=		sbin/ejabberdctl ${ROOT_USER} ${EJABBERD_GROUP} 0750

REPLACE_SH=		ejabberdctl.template tools/captcha.sh

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in
SUBST_FILES.paths+=	ejabberd.yml.example
SUBST_FILES.paths+=	ejabberdctl.template
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_DB@,${EJABBERD_DB},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_LOGDIR@,${EJABBERD_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_PIDDIR@,${EJABBERD_PIDDIR},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@DISTNAME@,${DISTNAME},g'

# Helper target to refresh remote deps for tarring up
fetch-deps:
	cd ${WRKSRC} && ${RM} -rf deps && ${BUILD_MAKE_CMD} deps

post-extract:
	${LN} -s ${WRKDIR}/deps ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dev.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/features.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
