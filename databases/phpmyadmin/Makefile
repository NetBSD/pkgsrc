# $NetBSD: Makefile,v 1.1.1.1 2001/07/08 20:53:04 tron Exp $

DISTNAME=	phpMyAdmin-2.2.0rc1
PKGNAME=	phpmyadmin-2.1.99.1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpmyadmin/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://phpwizard.net/projects/phpMyAdmin/
COMMENT=	Set of PHP-scripts to adminstrate MySQL over the WWW

DEPENDS+=	php-mysql>=4.0.5:../../www/php4-mysql

NO_BUILD=	YES

DOC_FILES=	CREDITS DEVELOPERS Documentation.html INSTALL LICENSE README \
		TODO

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpmyadmin/images
	${INSTALL_SCRIPT} ${WRKSRC}/*.php3 ${PREFIX}/share/phpmyadmin
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/phpmyadmin/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpmyadmin
	for FILE in ${DOC_FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/phpmyadmin; \
	done

.include "../../mk/bsd.pkg.mk"
