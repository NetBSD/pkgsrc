# $NetBSD: Makefile,v 1.1.1.1 2001/01/24 22:44:13 jlam Exp $

DISTNAME=	squirrelmail-1.0pre3
PKGNAME=	squirrelmail-0.9.3
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/} \
		http://nerf-herder.net/squirrel/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.squirrelmail.org/

DEPENDS+=	php>=4.0:../../www/php4

USE_PERL5=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL
MESSAGE_FILE=	${WRKDIR}/MESSAGE

SM_SUBDIR=	share/squirrelmail
SMDIR=		${PREFIX}/${SM_SUBDIR}

post-extract:
	cd ${WRKSRC};							\
	${MV} config/conf.pl config/conf.pl.orig;			\
	${SED}	-e "s|/usr/bin/perl|${PERL5}|g"				\
		config/conf.pl.orig > config/conf.pl;			\
	${CHMOD} +x config/conf.pl					\

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

pre-install:
	${SED}	-e "s|@SM_SUBDIR@|${SM_SUBDIR}|g"			\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@SM_SUBDIR@|${SM_SUBDIR}|g"			\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHGRP@|${CHGRP}|g"				\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CHOWN@|${CHOWN}|g"				\
		-e "s|@CP@|${CP}|g"					\
		-e "s|@MKDIR@|${MKDIR}|g"				\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED}	-e "s|@SMDIR@|${SMDIR}|g"				\
		${PKGDIR}/MESSAGE > ${MESSAGE_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${SMDIR}
	${CP} -R ${WRKSRC}/* ${SMDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${SMDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
