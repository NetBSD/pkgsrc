# $NetBSD: Makefile,v 1.11 2001/07/13 07:09:19 jlam Exp $

DISTNAME=	squirrelmail-1.0.6
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/} \
		http://nerf-herder.net/squirrel/ \
		ftp://nerf-herder.net/pub/squirrel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	PHP4 webmail package

DEPENDS+=	php>=4.0.4.1nb1:../../www/php4

USE_PERL5=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

APACHE_SYSCONFDIR?=	${LOCALBASE}/etc/httpd
BUILD_DEFS+=		APACHE_SYSCONFDIR
MESSAGE_SUBST+=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/squirrelmail
SMDIR=			${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		SMDIR=${SMDIR:S/^${PREFIX}\///}
FILES_SUBST+=		APACHE_SYSCONFDIR=${APACHE_SYSCONFDIR}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHGRP=${CHGRP:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

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
	${SED}	-e "s|@SMDIR@|${SMDIR}|g"				\
		${FILESDIR}/squirrelmail.conf.dist			\
		> ${WRKDIR}/squirrelmail.conf.dist
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${SMDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} squirrelmail.conf.dist		\
		${EGDIR}/squirrelmail.conf
	${CP} -R ${WRKSRC}/* ${SMDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}
	${CHMOD} -R a-w ${SMDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
