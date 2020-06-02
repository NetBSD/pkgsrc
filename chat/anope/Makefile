# $NetBSD: Makefile,v 1.34 2020/06/02 08:23:17 adam Exp $

DISTNAME=	anope-2.0.7-source
PKGNAME=	${DISTNAME:S/-source//1}
PKGREVISION=	6
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
CMAKE_ARGS+=	-DCONF_DIR=${PKG_SYSCONFDIR}
CMAKE_ARGS+=	-DLIB_DIR=lib/anope
CMAKE_ARGS+=	-DLOCALE_DIR=${PKGLOCALEDIR}/locale
CMAKE_ARGS+=	-DLOGS_DIR=anope/logs

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	anope

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
SUBST_VARS.conf=	PREFIX PKG_SYSCONFDIR

RCD_SCRIPTS=	anope

EGDIR=		${PREFIX}/share/examples/anope
DOCDIR=		${PREFIX}/share/doc/anope

USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${DOCDIR}

CONF_FILES+=	${EGDIR}/botserv.conf ${PKG_SYSCONFDIR}/botserv.conf
CONF_FILES+=	${EGDIR}/chanserv.conf ${PKG_SYSCONFDIR}/chanserv.conf
CONF_FILES+=	${EGDIR}/chanstats.conf ${PKG_SYSCONFDIR}/chanstats.conf
CONF_FILES+=	${EGDIR}/services.conf ${PKG_SYSCONFDIR}/services.conf
CONF_FILES+=	${EGDIR}/global.conf ${PKG_SYSCONFDIR}/global.conf
CONF_FILES+=	${EGDIR}/hostserv.conf ${PKG_SYSCONFDIR}/hostserv.conf
CONF_FILES+=	${EGDIR}/irc2sql.conf ${PKG_SYSCONFDIR}/irc2sql.conf
CONF_FILES+=	${EGDIR}/memoserv.conf ${PKG_SYSCONFDIR}/memoserv.conf
CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=	${EGDIR}/nickserv.conf ${PKG_SYSCONFDIR}/nickserv.conf
CONF_FILES+=	${EGDIR}/operserv.conf ${PKG_SYSCONFDIR}/operserv.conf

.include "options.mk"

pre-configure:
.for srcfile in ${ANOPE_EXTRAS}
	${LN} -sf ${WRKSRC}/modules/extra/${srcfile} ${WRKSRC}/modules/${srcfile}
.endfor

post-install:
	${MV} ${DESTDIR}${EGDIR}/botserv.example.conf \
		${DESTDIR}${EGDIR}/botserv.conf
	${MV} ${DESTDIR}${EGDIR}/chanserv.example.conf \
		${DESTDIR}${EGDIR}/chanserv.conf
	${MV} ${DESTDIR}${EGDIR}/chanstats.example.conf \
		${DESTDIR}${EGDIR}/chanstats.conf
	${MV} ${DESTDIR}${EGDIR}/example.conf \
		${DESTDIR}${EGDIR}/services.conf
	${MV} ${DESTDIR}${EGDIR}/global.example.conf \
		${DESTDIR}${EGDIR}/global.conf
	${MV} ${DESTDIR}${EGDIR}/hostserv.example.conf \
		${DESTDIR}${EGDIR}/hostserv.conf
	${MV} ${DESTDIR}${EGDIR}/irc2sql.example.conf \
		${DESTDIR}${EGDIR}/irc2sql.conf
	${MV} ${DESTDIR}${EGDIR}/memoserv.example.conf \
		${DESTDIR}${EGDIR}/memoserv.conf
	${MV} ${DESTDIR}${EGDIR}/modules.example.conf \
		${DESTDIR}${EGDIR}/modules.conf
	${MV} ${DESTDIR}${EGDIR}/nickserv.example.conf \
		${DESTDIR}${EGDIR}/nickserv.conf
	${MV} ${DESTDIR}${EGDIR}/operserv.example.conf \
		${DESTDIR}${EGDIR}/operserv.conf
	${MV} ${DESTDIR}${EGDIR}/example.chk \
		${DESTDIR}${DOCDIR}/example.chk
	${MV} ${DESTDIR}${EGDIR}/stats.standalone.example.conf \
		${DESTDIR}${DOCDIR}/stats.standalone.example.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
