# $NetBSD: Makefile,v 1.23 2018/08/22 09:46:08 wiz Exp $
#

DISTNAME=		ucspi-ssl-0.99e
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/ucspi-ssl/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/ucspi-ssl.html
COMMENT=		Command-line tools for SSL client-server applications

WRKSRC=			${WRKDIR}/host/superscript.com/net/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES
DJB_RESTRICTED=		no

SSL_SCRIPTS=		https@ sslcat sslconnect
SSL_PROGRAMS=		sslclient sslserver
SSL_MAN1PAGES=		${SSL_SCRIPTS:S/$/.1/g} ${SSL_PROGRAMS:S/$/.1/g}
SSL_MAN2PAGES=		ucspi-tls.2

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	do-configure
SUBST_FILES.prefix=	${SSL_SCRIPTS:S/^/src\//g:S/$/.sh/g}
SUBST_SED.prefix=	-e 's|HOME/command/|${PREFIX}/bin/|g'
SUBST_MESSAGE.prefix=	Fixing prefix.

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	src/dns_rcrw.c
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'
SUBST_MESSAGE.etc=	Fixing prefix.

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
	${ECHO} ${PREFIX}/bin > conf-tcpbin;				\
	${ECHO} > conf-ssl;						\
	${ECHO} ${SSLDIR}/certs > conf-cadir;				\
	${ECHO} ${PKG_SYSCONFDIR}/dh1024.pem > conf-dhfile;

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man2 share/doc/${PKGBASE} ${EGDIR}

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

.	for i in CERTS CHAIN-SSL CHANGES TODO UCSPI-SSL
	  ${INSTALL_DATA} ${WRKSRC}/doc/${i} \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.	endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
