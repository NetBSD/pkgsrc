# $NetBSD: Makefile,v 1.2 1999/02/23 18:28:34 rh Exp $
# FreeBSD Id: Makefile,v 1.14 1998/11/09 09:24:20 max Exp
#

DISTNAME=	delegate5.8.8
PKGNAME=	delegate-5.8.8
CATEGORIES=	net
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://wall.etl.go.jp/delegate/

MAKE_ENV=	PATH=$${PATH}:.

DELEGATE_MANAGER?=	root@localhost

pre-build:
	@echo "MANAGER=${DELEGATE_MANAGER}" >> ${WRKSRC}/DELEGATE_CONF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	${SED} -e 's:__PREFIX__:${PREFIX}:g' \
	    -e 's:__MANAGER__:${DELEGATE_MANAGER}:g' \
	    ${WRKSRC}/delegated.sh.template \
	    > ${WRKSRC}/delegated.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/delegated.sh.sample \
	   ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.txt \
	   ${PREFIX}/man/cat8/delegated.0
	@${MKDIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/tutor-en.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-en.html
	${INSTALL_DATA} ${WRKSRC}/tutor-jp.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-jp.html

.include "../../mk/bsd.pkg.mk"
