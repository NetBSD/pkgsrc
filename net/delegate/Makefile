# $NetBSD: Makefile,v 1.27 2004/04/27 20:51:10 reed Exp $
# FreeBSD Id: Makefile,v 1.14 1998/11/09 09:24:20 max Exp
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	delegate-8.5.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/ \
		ftp://etlport.etl.go.jp/pub/DeleGate/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Net/WWW/server/delegate/ \
		ftp://ftp.nec.co.jp/pub/infosys/WWW/DeleGate/ \
		ftp://ftp.fujitsu.co.jp/pub/networking/DeleGate/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/delegate.org/ \
		ftp://ftp.eni.co.jp/pub/mirrors/delegate/ \
		ftp://ftp.ntua.gr/pub/net/gwtools/DeleGate/ \
		ftp://ftp.netsw.org/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.de/ftp/data/ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.delegate.org/
COMMENT=	General purpose TCP/IP proxy system

USE_PKGINSTALL=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		DELEGATE_MANAGER
DELEGATE_MANAGER?=	root@localhost

RCD_SCRIPTS=		delegated
FILES_SUBST+=		ADMIN="${DELEGATE_MANAGER}"

OWN_DIRS_PERMS+=	/var/spool/delegate/cache \
			${ROOT_USER} ${ROOT_GROUP} 1777
OWN_DIRS_PERMS+=	/var/spool/delegate-nobody nobody nobody 755

pre-build:
	@${ECHO} "ADMIN=${DELEGATE_MANAGER}" >> ${WRKSRC}/DELEGATE_CONF

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/delegated ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/Manual.htm \
	   ${PREFIX}/share/doc/delegate/manual.html
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/delegate
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-en.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-en.html
	${INSTALL_DATA} ${WRKSRC}/doc/tutor-jp.htm \
	   ${PREFIX}/share/doc/delegate/tutorial-jp.html

.include "../../mk/bsd.pkg.mk"
