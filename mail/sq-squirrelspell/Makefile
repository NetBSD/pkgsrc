# $NetBSD: Makefile,v 1.5 2001/11/19 16:23:11 jlam Exp $

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

NO_BUILD=	# defined

CONF_FILES=	${SMDIR}/plugins/squirrelspell/sqspell_config.dist	\
		${SMDIR}/plugins/squirrelspell/sqspell_config.php
OWN_DIRS=	${SMDIR}/plugins/squirrelspell

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

do-install:
	${CP} -R ${WRKSRC} ${SMDIR}/plugins

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
