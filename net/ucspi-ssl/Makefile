# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:26 ryoon Exp $
#

DISTNAME=		ucspi-ssl-0.99
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.fehcom.de/ipnet/ucspi-ssl/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.fehcom.de/ipnet/ucspi-ssl.html
COMMENT=		Command-line tools for SSL client-server applications

DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

WRKSRC=			${WRKDIR}/host/superscript.com/net/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES
DJB_RESTRICTED=		no

SSL_SCRIPTS=		https@ sslcat sslconnect
SSL_PROGRAMS=		sslclient sslserver

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	${SSL_SCRIPTS:S/^/src\//g:S/$/.sh/g}
SUBST_SED.paths=	-e 's|HOME/command/|${PREFIX}/bin/|g'
SUBST_MESSAGE.paths=	Fixing paths.

PLIST_SRC=		${PKGDIR}/PLIST

DJB_CONFIG_DIR=		${WRKSRC}
DJB_CONFIG_CMDS=							\
	${ECHO} ${PREFIX}/bin > conf-tcpbin;				\
	${ECHO} > conf-ssl;						\
	${ECHO} ${SSLDIR} > conf-cadir;

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin share/doc/ucspi-ssl

do-install:
.	for i in ${SSL_SCRIPTS}
	  ${INSTALL_SCRIPT} ${WRKSRC}/command/${i} ${DESTDIR}${PREFIX}/bin
.	endfor

.	for i in ${SSL_PROGRAMS}
	  ${INSTALL_PROGRAM} ${WRKSRC}/command/${i} ${DESTDIR}${PREFIX}/bin
.	endfor

.	for i in CHANGES TODO UCSPI-SSL
	  ${INSTALL_DATA} ${WRKSRC}/doc/${i} \
	    ${DESTDIR}${PREFIX}/share/doc/ucspi-ssl
.	endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
