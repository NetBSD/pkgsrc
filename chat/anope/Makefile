# $NetBSD: Makefile,v 1.27 2019/07/20 22:46:10 wiz Exp $

DISTNAME=	anope-2.0.6-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=anope/}
GITHUB_PROJECT=	anope
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.anope.org/
COMMENT=	Modular set of IRC services
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPROGRAM_NAME=anope

CMAKE_ARGS+=	-DDISABLE_TOOLS=ON

CMAKE_ARGS+=	-DDB_DIR=anope/data
CMAKE_ARGS+=	-DCONF_DIR=${PKG_SYSCONFDIR}/anope
CMAKE_ARGS+=	-DLIB_DIR=lib/anope
CMAKE_ARGS+=	-DLOCALE_DIR=${PKGLOCALEDIR}/locale
CMAKE_ARGS+=	-DLOGS_DIR=anope/logs

.include "../../mk/bsd.prefs.mk"

ANOPE_USER?=		anope
ANOPE_GROUP?=		anope
PKG_GROUPS=		${ANOPE_GROUP}
PKG_USERS=		${ANOPE_USER}:${ANOPE_GROUP}
PKG_GROUPS_VARS=	ANOPE_USER
PKG_USERS_VARS=		ANOPE_GROUP

OWN_DIRS_PERMS+=	${PREFIX}/anope ${ANOPE_USER} ${ANOPE_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/anope/data ${ANOPE_USER} ${ANOPE_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/anope/logs ${ANOPE_USER} ${ANOPE_GROUP} 0755

FILES_SUBST+=		ANOPE_GROUP=${ANOPE_GROUP:Q}
FILES_SUBST+=		ANOPE_USER=${ANOPE_USER:Q}
FILES_SUBST+=		PKGLOCALEDIR=${PKGLOCALEDIR}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set variables in configuration file.
SUBST_FILES.conf+=	data/example.conf
SUBST_VARS.conf=	PREFIX
SUBST_VARS.conf+=	PKG_SYSCONFDIR
SUBST_VARS.conf+=	PKGLOCALEDIR

RCD_SCRIPTS=	anope

EGDIR=		${PREFIX}/share/examples/anope
DOCDIR=		${PREFIX}/share/doc/anope

USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${DOCDIR}

CONF_FILES+=	${EGDIR}/botserv.conf ${PKG_SYSCONFDIR}/anope/botserv.conf
CONF_FILES+=	${EGDIR}/chanserv.conf ${PKG_SYSCONFDIR}/anope/chanserv.conf
CONF_FILES+=	${EGDIR}/chanstats.conf ${PKG_SYSCONFDIR}/anope/chanstats.conf
CONF_FILES+=	${EGDIR}/services.conf ${PKG_SYSCONFDIR}/anope/services.conf
CONF_FILES+=	${EGDIR}/global.conf ${PKG_SYSCONFDIR}/anope/global.conf
CONF_FILES+=	${EGDIR}/hostserv.conf ${PKG_SYSCONFDIR}/anope/hostserv.conf
CONF_FILES+=	${EGDIR}/irc2sql.conf ${PKG_SYSCONFDIR}/anope/irc2sql.conf
CONF_FILES+=	${EGDIR}/memoserv.conf ${PKG_SYSCONFDIR}/anope/memoserv.conf
CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/anope/modules.conf
CONF_FILES+=	${EGDIR}/nickserv.conf ${PKG_SYSCONFDIR}/anope/nickserv.conf
CONF_FILES+=	${EGDIR}/operserv.conf ${PKG_SYSCONFDIR}/anope/operserv.conf

.include "options.mk"

pre-configure:
.for srcfile in ${ANOPE_EXTRAS}
	${LN} -sf ${WRKSRC}/modules/extra/${srcfile} ${WRKSRC}/modules/${srcfile}
.endfor

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/botserv.example.conf \
		${DESTDIR}${EGDIR}/botserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/chanserv.example.conf \
		${DESTDIR}${EGDIR}/chanserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/chanstats.example.conf \
		${DESTDIR}${EGDIR}/chanstats.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/example.conf \
		${DESTDIR}${EGDIR}/services.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/global.example.conf \
		${DESTDIR}${EGDIR}/global.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/hostserv.example.conf \
		${DESTDIR}${EGDIR}/hostserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/irc2sql.example.conf \
		${DESTDIR}${EGDIR}/irc2sql.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/memoserv.example.conf \
		${DESTDIR}${EGDIR}/memoserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/modules.example.conf \
		${DESTDIR}${EGDIR}/modules.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/nickserv.example.conf \
		${DESTDIR}${EGDIR}/nickserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/operserv.example.conf \
		${DESTDIR}${EGDIR}/operserv.conf
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/example.chk \
		${DESTDIR}${DOCDIR}/example.chk
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/anope/stats.standalone.example.conf \
		${DESTDIR}${DOCDIR}/stats.standalone.example.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
