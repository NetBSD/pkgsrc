# $NetBSD: Makefile,v 1.1.1.1 2001/05/16 07:57:24 jlam Exp $

DISTNAME=	squirrelspell.0.3.5-1.0.6
PKGNAME=	sq-squirrelspell-0.3.5
WRKSRC=		${WRKDIR}/squirrelspell
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://mricon.com/xmlparse/SM/index.xml
COMMENT=	SquirrelMail spell-checker plugin

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=	php-mcrypt>=4.0.4.1:../../www/php4-mcrypt
DEPENDS+=	squirrelmail>=1.0.6:../../mail/squirrelmail

SMDIR=		${PREFIX}/share/squirrelmail

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

pre-install:
	${SED}	-e "s|@SMDIR@|${SMDIR:S/^${PREFIX}\///}|g"		\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@RM@|${RM}|g"					\
		-e "s|@RMDIR@|${RMDIR}|g"				\
		-e "s|@TRUE@|${TRUE}|g"					\
		${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s|@SMDIR@|${SMDIR:S/^${PREFIX}\///}|g"		\
		-e "s|@CAT@|${CAT}|g"					\
		-e "s|@CHMOD@|${CHMOD}|g"				\
		-e "s|@CP@|${CP}|g"					\
		${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${CP} -R ${WRKSRC} ${SMDIR}/plugins

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
