# $NetBSD: Makefile,v 1.17 2000/10/15 17:24:28 rh Exp $
# FreeBSD Id: Makefile,v 1.14 1998/11/09 09:24:20 max Exp
#

DISTNAME=	${PKGNAME:S/-//}
PKGNAME=	delegate-6.1.18
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/ \
		ftp://etlport.etl.go.jp/pub/DeleGate/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Net/WWW/server/delegate/ \
		ftp://ftp.nec.co.jp/pub/infosys/WWW/DeleGate/ \
		ftp://ftp.fujitsu.co.jp/pub/networking/DeleGate/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/ \
		ftp://ftp.eni.co.jp/pub/mirrors/delegate/ \
		ftp://ftp.ntua.gr/pub/net/gwtools/DeleGate/ \
		ftp://ftp.netsw.org/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.de/ftp/data/ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://www.delegate.org/

DEPENDS+=	readline>=4.0:../../devel/readline

DELEGATE_MANAGER?=	root@localhost

pre-build:
	@${ECHO} "ADMIN=${DELEGATE_MANAGER}" >> ${WRKSRC}/DELEGATE_CONF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	${SED} -e 's:__PREFIX__:${PREFIX}:g' \
	    -e 's:__ADMIN__:${DELEGATE_MANAGER}:g' \
	    ${WRKSRC}/delegated.sh.template \
	    > ${WRKSRC}/delegated.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/delegated.sh.sample \
	   ${PREFIX}/etc/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.htm \
	   ${PREFIX}/share/doc/delegate/manual.html
	@${MKDIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-en.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-en.html
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-jp.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-jp.html

.include "../../mk/bsd.pkg.mk"
