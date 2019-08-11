# $NetBSD: Makefile,v 1.36 2019/08/11 13:22:31 wiz Exp $
#

DISTNAME=		ucspi-ssl-0.10.11
PKGNAME=		${DISTNAME:S/-0./-0.999./}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/ucspi-ssl/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/ucspi-ssl.html
COMMENT=		Command-line tools for SSL client-server applications

WRKSRC=			${WRKDIR}/host/superscript.com/net/${DISTNAME}
DJB_SLASHPACKAGE=	YES
DJB_RESTRICTED=		no

SSL_SCRIPTS=		https@ sslcat sslconnect
SSL_PROGRAMS=		sslclient sslserver
SSL_MAN1PAGES=		${SSL_SCRIPTS:S/$/.1/g} ${SSL_PROGRAMS:S/$/.1/g}
SSL_MAN1PAGES+=		sslhandle.1
SSL_MAN2PAGES=		ucspi-tls.2

PKG_USERS_VARS+=	UCSPI_SSL_USER
PKG_GROUPS_VARS+=	UCSPI_SSL_GROUP
PKG_GROUPS+=		${UCSPI_SSL_GROUP}
PKG_USERS+=		${UCSPI_SSL_USER}:${UCSPI_SSL_GROUP}

BUILD_DEFS+=		PKG_SYSCONFBASE
PKG_SYSCONFSUBDIR=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_DIRS+=		${PKG_SYSCONFDIR}
CONF_FILES+=		${EGDIR}/dh1024.pem ${PKG_SYSCONFDIR}/dh1024.pem

DJB_CONFIG_DIR=		${WRKSRC}
DJB_CONFIG_CMDS=							\
	${ECHO} > conf-ssl;						\
	${ECHO} ${SSLDIR}/certs > conf-cadir;				\
	${ECHO} ${PKG_SYSCONFDIR}/dh1024.pem > conf-dhfile;		\
	${ECHO} ${DEFAULT_MEDIUM_CIPHERS} > conf-ciphers;

# from `postconf -d | grep tls_medium_cipherlist`
DEFAULT_MEDIUM_CIPHERS=	aNULL:-aNULL:ALL:!EXPORT:!LOW:+RC4:@STRENGTH

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man2 share/doc/${PKGBASE} ${EGDIR}

do-test:
	cd ${WRKSRC}; \
		./package/rts

do-install: do-install-sslperl
.	for i in ${SSL_SCRIPTS}
	  ${INSTALL_SCRIPT} ${WRKSRC}/command/${i} ${DESTDIR}${PREFIX}/bin
.	endfor

.	for i in ${SSL_PROGRAMS}
	  ${INSTALL_PROGRAM} ${WRKSRC}/command/${i} ${DESTDIR}${PREFIX}/bin
.	endfor

.	for i in ${SSL_MAN1PAGES}
	  ${INSTALL_MAN} ${WRKSRC}/man/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.	endfor

.	for i in ${SSL_MAN2PAGES}
	  ${INSTALL_MAN} ${WRKSRC}/man/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man2
.	endfor

.	for i in dh1024.pem
	  ${INSTALL_DATA} ${WRKSRC}/etc/${i} ${DESTDIR}${EGDIR}
.	endfor

.	for i in CERTS CHAIN-SSL CHANGES TLSVERSION_CIPHERSUITES TLS_1_3 TODO UCSPI-SSL
	  ${INSTALL_DATA} ${WRKSRC}/doc/${i} \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.	endfor

.include "../../net/fehqlibs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
