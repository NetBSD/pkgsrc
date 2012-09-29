# $NetBSD: Makefile,v 1.28 2012/09/29 15:56:31 tron Exp $

DISTNAME=	ejabberd-2.1.10
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.process-one.net/downloads/ejabberd/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ejabberd.im/
COMMENT=	Free and Open Source distributed fault-tolerant Jabber server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	jabberd-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
# much prefer to be explicit about the configure settings rather than
# depending on the defaults to continue to be sane or same between versions
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--enable-mod_irc
CONFIGURE_ARGS+=	--enable-mod_muc
CONFIGURE_ARGS+=	--enable-eldap
CONFIGURE_ARGS+=	--enable-web
CONFIGURE_ARGS+=	--enable-tls
CONFIGURE_ARGS+=	--enable-ejabberd_zlib
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-libiconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-erlang=${BUILDLINK_PREFIX.erlang}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

CONFIGURE_DIRS+=	src
BUILD_DIRS+=		src

MAKE_ENV=		PKGVERSION=${PKGVERSION}
PLIST_SUBST+=		DISTNAME=${DISTNAME} PKGBASE=${PKGBASE}

FILES_SUBST+=		DISTNAME=${DISTNAME} PKGBASE=${PKGBASE}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=		EGDIR=${EGDIR}

RCD_SCRIPTS=		ejabberd

BUILD_DEFS+=		EJABBERD_USER EJABBERD_GROUP EJABBERD_LOGDIR
BUILD_DEFS+=		EJABBERD_PIDDIR EJABBERD_DB EJABBERD_TRANSDIR
BUILD_DEFS+=		EJABBERD_EXDIR
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	ejabberd

.include "../../mk/bsd.prefs.mk"

EJABBERD_USER?=		ejabberd
EJABBERD_GROUP?=	ejabberd
EJABBERD_PIDDIR?=	${VARBASE}/run/ejabberd
EJABBERD_LOGDIR?=	${VARBASE}/log/ejabberd
EJABBERD_DB?=		${VARBASE}/spool/ejabberd
EJABBERD_EXDIR=		share/examples/ejabberd

OWN_DIRS+=		${EJABBERD_PIDDIR}
OWN_DIRS+=		${EJABBERD_LOGDIR}
OWN_DIRS+=		${EJABBERD_DB}
OWN_DIRS_PERMS+=	${EJABBERD_PIDDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_LOGDIR} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770
OWN_DIRS_PERMS+=	${EJABBERD_DB} ${EJABBERD_USER} ${EJABBERD_GROUP} 0770

FILES_SUBST+=		JABBERD_USER=${EJABBERD_USER}
FILES_SUBST+=		JABBERD_LOGDIR=${EJABBERD_LOGDIR}

PLIST_SUBST+=		EJABBERD_EXDIR=${EJABBERD_EXDIR}

PKG_GROUPS+=		${EJABBERD_GROUP}
PKG_USERS+=		${EJABBERD_USER}:${EJABBERD_GROUP}
PKG_GECOS.${EJABBERD_USER}=	ejabberd user
PKG_HOME.${EJABBERD_USER}=	${EJABBERD_DB}

EGDIR=			${PREFIX}/${EJABBERD_EXDIR}

INSTALLATION_DIRS+=	${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}

CONF_FILES=		${EGDIR}/ejabberd.cfg ${PKG_SYSCONFDIR}/ejabberd.cfg
CONF_FILES+=		${EGDIR}/ejabberdctl.cfg ${PKG_SYSCONFDIR}/ejabberdctl.cfg
CONF_FILES+=		${EGDIR}/inetrc ${PKG_SYSCONFDIR}/inetrc

REPLACE_SH=		src/ejabberdctl.template tools/captcha.sh

post-patch:
	${RM} -f ${WRKSRC}/doc/guide.tex.orig

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/dev.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/features.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Localizing paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Makefile.in
SUBST_FILES.paths+=	src/ejabberd.cfg.example
SUBST_FILES.paths+=	src/ejabberdctl.template
SUBST_FILES.paths+=	doc/guide.tex
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@JABBERD_LOGDIR@,${EJABBERD_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_DBDIR@,${EJABBERD_DB},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_LOGDIR@,${EJABBERD_LOGDIR},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_PIDDIR@,${EJABBERD_PIDDIR},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_DB@,${EJABBERD_DB},g'
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@DISTNAME@,${DISTNAME},g'
SUBST_SED.paths+=	-e 's,@EJABBERD_VARDIR@,${VARBASE},g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
