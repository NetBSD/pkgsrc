# $NetBSD: Makefile,v 1.3 1999/03/01 06:46:32 rh Exp $
# FreeBSD Id: Makefile,v 1.14 1998/11/09 09:24:20 max Exp
#

DISTNAME=	delegate5.8.8
PKGNAME=	delegate-5.8.8
CATEGORIES=	net
MASTER_SITES=	ftp://etlport.etl.go.jp/pub/DeleGate/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Net/WWW/server/delegate/ \
		ftp://ftp.nec.co.jp/pub/infosys/WWW/DeleGate/ \
		ftp://ftp.fujitsu.co.jp/pub/networking/DeleGate/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/ \
		ftp://ftp.eni.co.jp/pub/mirrors/delegate/

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
