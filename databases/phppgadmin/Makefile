# $NetBSD: Makefile,v 1.7 2004/04/25 01:14:56 xtraeme Exp $

DISTNAME=	phpPgAdmin_2-4-2
PKGNAME=	phppgadmin-2.4.2
PKGREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phppgadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	sjr@hispabsd.org
HOMEPAGE=	http://phppgadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer PostgreSQL over the WWW

DEPENDS+=	php-pgsql>=4.1.2:../../databases/php4-pgsql

WRKSRC=		${WRKDIR}/${DISTNAME:S/_2-4-2//}
NO_BUILD=	YES
NO_BUILDLINK=	YES

DOC_FILES=	BUGS ChangeLog Documentation.html \
		INSTALL README TODO

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/phppgadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phppgadmin/images
	${INSTALL_SCRIPT} ${WRKSRC}/*.js ${PREFIX}/share/phppgadmin
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${PREFIX}/share/phppgadmin
	${INSTALL_SCRIPT} ${WRKSRC}/config.inc.php-dist ${PREFIX}/share/phppgadmin
	${INSTALL_DATA} ${WRKSRC}/images/*.* ${PREFIX}/share/phppgadmin/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phppgadmin
	for f in ${DOC_FILES}; do					\
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/phppgadmin;	\
	done

.include "../../mk/bsd.pkg.mk"
