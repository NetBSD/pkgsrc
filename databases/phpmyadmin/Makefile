# $NetBSD: Makefile,v 1.7 2003/01/05 08:41:45 tron Exp $

DISTNAME=	phpMyAdmin-2.3.2-php
PKGNAME=	phpmyadmin-2.3.2
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://phpwizard.net/projects/phpMyAdmin/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	php-mysql>=4.0.5:../../databases/php4-mysql
DEPENDS+=	php-pcre>=4.0.5:../../devel/php4-pcre

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${DISTNAME:S/-php//}

DOC_FILES=	ANNOUNCE.txt CREDITS ChangeLog Documentation.html \
		Documentation.txt INSTALL LICENSE README RELEASE-DATE-2.3.2 \
		TODO

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/auth
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/fpdf
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/fpdf/font
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/libraries/xpath
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/badwords.txt ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/phpmyadmin/images
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.php ${PREFIX}/share/phpmyadmin/lang
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/*.* ${PREFIX}/share/phpmyadmin/libraries
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/auth/*.php ${PREFIX}/share/phpmyadmin/libraries/auth
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/*.php ${PREFIX}/share/phpmyadmin/libraries/fpdf
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/fpdf/font/*.php ${PREFIX}/share/phpmyadmin/libraries/fpdf/font
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/xpath/*.php ${PREFIX}/share/phpmyadmin/libraries/xpath
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.* ${PREFIX}/share/phpmyadmin/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	for FILE in ${DOC_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/phpmyadmin; \
	done

.include "../../mk/bsd.pkg.mk"
