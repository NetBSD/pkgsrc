# $NetBSD: Makefile,v 1.15 2001/12/11 06:15:16 jlam Exp $

DISTNAME=	squirrelmail-1.0.6
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/} \
		http://nerf-herder.net/squirrel/ \
		ftp://nerf-herder.net/pub/squirrel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP4 webmail package

DEPENDS+=	php>=4.0.6:../../www/php4
DEPENDS+=	php-session>=4.0.6:../../devel/php4-session

USE_PERL5=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
DATADIR=		/var/spool/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}
FILES_SUBST+=		SMDIR=${SMDIR}

CONF_FILES=	${SMDIR}/config/config_default.php ${SMDIR}/config/config.php
CONF_FILES+=	${SMDIR}/data/default_pref ${DATADIR}/data/default_pref
CONF_FILES+=	${EGDIR}/squirrelmail.conf ${PKG_SYSCONFDIR}/squirrelmail.conf
OWN_DIRS=		${DATADIR}
OWN_DIRS+=		${SMDIR} ${SMDIR}/config
OWN_DIRS_PERMS=		${DATADIR}/attachments root nobody 730
OWN_DIRS_PERMS+=	${DATADIR}/data nobody nobody 755

post-extract:
	cd ${WRKSRC};							\
	${MV} config/conf.pl config/conf.pl.orig;			\
	${SED}	-e "s|^#!/.*|#!${PERL5}|g"				\
		config/conf.pl.orig > config/conf.pl;			\
	${CHMOD} +x config/conf.pl
	${FIND} ${WRKSRC} -name ".cvsignore" -exec ${RM} -f {} \;

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

pre-install:
	${SED}	${FILES_SUBST_SED}					\
		${FILESDIR}/squirrelmail.conf.dist			\
		> ${WRKDIR}/squirrelmail.conf.dist

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${SMDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} squirrelmail.conf.dist		\
		${EGDIR}/squirrelmail.conf
	${CP} -R ${WRKSRC}/* ${SMDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	${CHMOD} -R a-w ${SMDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
