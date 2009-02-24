# $NetBSD: Makefile,v 1.37 2009/02/24 03:24:15 rh Exp $

DISTNAME=	delegate9.9.1
PKGNAME=	delegate-9.9.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.delegate.org/pub/DeleGate/ \
		ftp://etlport.etl.go.jp/pub/DeleGate/ \
		ftp://ftp.fujitsu.co.jp/pub/networking/DeleGate/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/DeleGate/delegate.org/ \
		ftp://ftp.ntua.gr/pub/net/gwtools/DeleGate/ \
		ftp://ftp.netsw.org/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/ \
		ftp://ftp.ecrc.de/ftp/data/ftp.ecrc.net/pub/netsw/Network/IP/Firewall/Proxy/delegate/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.delegate.org/delegate/
COMMENT=	General purpose TCP/IP proxy system


.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		DELEGATE_MANAGER
BUILD_DEFS+=		VARBASE
DELEGATE_MANAGER?=	root@localhost

RCD_SCRIPTS=		delegated
FILES_SUBST+=		ADMIN=${DELEGATE_MANAGER:Q}

OWN_DIRS_PERMS+=${VARBASE}/spool/delegate/cache ${ROOT_USER} ${ROOT_GROUP} 1777
OWN_DIRS_PERMS+=${VARBASE}/spool/delegate-nobody nobody nobody 755

INSTALLATION_DIRS=	sbin

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
