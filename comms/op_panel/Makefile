# $NetBSD: Makefile,v 1.19 2022/06/28 11:31:06 wiz Exp $
#

DISTNAME=	op_panel-0.30
#PKGREVISION=	9
PKGREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://www.asternic.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.asternic.org/
COMMENT=	Flash Operator Panel for Asterisk
LICENSE=	gnu-gpl-v2

FOP=		op_panel
MESSAGE_SUBST+=	FOP=${FOP}

RCD_SCRIPTS+=	${FOP}

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL+=	op_server.pl

PKG_GROUPS_VARS=	APACHE_GROUP
PKG_USERS_VARS=		APACHE_USER

PKG_SYSCONFSUBDIR=	${FOP}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/${FOP}
SMDIR=			${PREFIX}/share/${FOP}

MESSAGE_SUBST+=		SMDIR=${SMDIR}
FILES_SUBST+=		SMDIR=${SMDIR}

CONF_FILES=		${EGDIR}/op_astdb.cfg ${PKG_SYSCONFDIR}/op_astdb.cfg
CONF_FILES+=		${EGDIR}/op_buttons.cfg ${PKG_SYSCONFDIR}/op_buttons.cfg
CONF_FILES+=		${EGDIR}/op_lang_ca.cfg ${PKG_SYSCONFDIR}/op_lang_ca.cfg
CONF_FILES+=		${EGDIR}/op_lang_de.cfg ${PKG_SYSCONFDIR}/op_lang_de.cfg
CONF_FILES+=		${EGDIR}/op_lang_en.cfg ${PKG_SYSCONFDIR}/op_lang_en.cfg
CONF_FILES+=		${EGDIR}/op_lang_es.cfg ${PKG_SYSCONFDIR}/op_lang_es.cfg
CONF_FILES+=		${EGDIR}/op_lang_gl.cfg ${PKG_SYSCONFDIR}/op_lang_gl.cfg
CONF_FILES+=		${EGDIR}/op_lang_it.cfg ${PKG_SYSCONFDIR}/op_lang_it.cfg
CONF_FILES+=		${EGDIR}/op_lang_no.cfg ${PKG_SYSCONFDIR}/op_lang_no.cfg
CONF_FILES+=		${EGDIR}/op_lang_ru.cfg ${PKG_SYSCONFDIR}/op_lang_ru.cfg
CONF_FILES+=		${EGDIR}/op_lang_se.cfg ${PKG_SYSCONFDIR}/op_lang_se.cfg
CONF_FILES+=		${EGDIR}/op_server.cfg ${PKG_SYSCONFDIR}/op_server.cfg
CONF_FILES+=		${EGDIR}/op_style.cfg ${PKG_SYSCONFDIR}/op_style.cfg
CONF_FILES+=		${EGDIR}/op_panel.conf ${PKG_SYSCONFDIR}/op_panel.conf

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/${FOP}.conf.dist
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	SMDIR
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	PERL5
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS+=	share/examples/${FOP}
INSTALLATION_DIRS+=	share/${FOP}
INSTALLATION_DIRS+=	libexec

post-extract:
	cp ${FILESDIR}/${FOP}.conf.dist \
		${WRKDIR}/${FOP}.conf.dist

do-install:
	${INSTALL_DATA} ${WRKDIR}/${FOP}.conf.dist ${DESTDIR}${EGDIR}/${FOP}.conf
	cp ${WRKSRC}/flash/* ${DESTDIR}${SMDIR}
	chown -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${SMDIR}
	find ${DESTDIR}${SMDIR} -type d -exec chmod ${PKGDIRMODE} {} \;
	find ${DESTDIR}${SMDIR} -type f -exec chmod ${SHAREMODE} {} \;
	${INSTALL_SCRIPT} ${WRKSRC}/op_server.pl ${DESTDIR}${PREFIX}/libexec/op_server.pl
	${INSTALL_DATA} ${WRKSRC}/op_*.cfg ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
