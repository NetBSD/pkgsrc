# $NetBSD: Makefile,v 1.5 2001/10/03 08:20:37 tron Exp $

DISTNAME=	phpMyAdmin-2.2.0-php
PKGNAME=	phpmyadmin-2.2.0
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://phpwizard.net/projects/phpMyAdmin/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	php-mysql>=4.0.5:../../www/php4-mysql
DEPENDS+=	php-pcre>=4.0.5:../../www/php4-pcre

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${DISTNAME:S/-php//}

DOC_FILES=	ANNOUNCE.txt CREDITS ChangeLog Documentation.html \
		Documentation.txt INSTALL LICENSE README RELEASE-DATE-2.2.0 \
		TODO

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_SCRIPT} ${WRKSRC}/*.js ${PREFIX}/share/phpmyadmin
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/phpmyadmin/images
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	for FILE in ${DOC_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/phpmyadmin; \
	done

.include "../../mk/bsd.pkg.mk"
