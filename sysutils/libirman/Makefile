# $NetBSD: Makefile,v 1.2 2002/05/17 13:06:09 abs Exp $
#

DISTNAME=	libirman-0.4.1b
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.evation.com/libirman/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.evation.com/libirman/libirman.html
COMMENT=	Programming library for Irman - infrared control

GNU_CONFIGURE=	YES

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/irman.conf ${PKG_SYSCONFDIR}/irman.conf

post-build:
	    ${SED}  -e "s:/usr/local/etc:${PKG_SYSCONFDIR}:g" \
		    -e "s:/usr/local:${PREFIX}:g" \
		    -e 's/test_func/irman_&/g' \
		    -e 's/test_io/irman_&/g' \
		    -e 's/test_name/irman_&/g' \
			${WRKSRC}/README > ${WRKSRC}/libirman.README

post-install:
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_func ${PREFIX}/bin/irman_test_func
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_io ${PREFIX}/bin/irman_test_io
	    ${INSTALL_PROGRAM} ${WRKSRC}/test_name ${PREFIX}/bin/irman_test_name
	    ${INSTALL_DATA} ${WRKSRC}/libirman.README \
					${PREFIX}/share/doc/libirman.README

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
