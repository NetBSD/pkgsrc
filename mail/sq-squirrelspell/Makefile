# $NetBSD: Makefile,v 1.4 2001/10/29 05:43:47 jmc Exp $

DISTNAME=	squirrelspell.0.3.5-1.0.6
PKGNAME=	sq-squirrelspell-0.3.5
WRKSRC=		${WRKDIR}/squirrelspell
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://mricon.com/xmlparse/SM/index.xml
COMMENT=	SquirrelMail spell-checker plugin

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=	php-mcrypt>=4.0.4.1:../../security/php4-mcrypt
DEPENDS+=	squirrelmail>=1.0.6:../../mail/squirrelmail

SMDIR=		${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=	SMDIR=${SMDIR}

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

FILES_SUBST=		SMDIR=${SMDIR:S/^${PREFIX}\///}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${CP} -R ${WRKSRC} ${SMDIR}/plugins

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
