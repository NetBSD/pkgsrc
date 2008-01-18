# $NetBSD: Makefile,v 1.3 2008/01/18 05:08:51 tnn Exp $
#

DISTNAME=		ucspi-ssl-0.70
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.superscript.com/ucspi-ssl/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.superscript.com/ucspi-ssl/intro.html
COMMENT=		Command-line tools for SSL client-server applications

DEPENDS+=		ucspi-tcp-[0-9]*:../../net/ucspi-tcp

WRKSRC=			${WRKDIR}/host/superscript.com/net/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES

SSL_SCRIPTS=		https@ sslcat sslconnect
SSL_PROGRAMS=		sslclient sslserver

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	${SSL_SCRIPTS:S/^/src\//g:S/$/.sh/g}
SUBST_SED.paths=	-e 's|HOME/command/|${PREFIX}/bin/|g'
SUBST_MESSAGE.paths=	Fixing paths.

PLIST_SRC=		${PKGDIR}/PLIST

DJB_CONFIG_CMDS=							\
	${ECHO} ${LOCALBASE}/bin > conf-tcpbin;				\
	${ECHO} > conf-ssl;						\
	${ECHO} ${PKG_SYSCONFDIR} > conf-cadir;

.include "../../mk/bsd.prefs.mk"

# from ../../security/openssl/Makefile
.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.ucspi-ssl?=	/etc/openssl
.endif
PKG_SYSCONFSUBDIR=	openssl

INSTALLATION_DIRS=	bin share/doc/ucspi-ssl

do-install:
.	for i in ${SSL_SCRIPTS}
	  ${INSTALL_SCRIPT} ${WRKSRC}/command/${i} ${PREFIX}/bin
.	endfor

.	for i in ${SSL_PROGRAMS}
	  ${INSTALL_PROGRAM} ${WRKSRC}/command/${i} ${PREFIX}/bin
.	endfor

.	for i in CHANGES TODO UCSPI-SSL
	  ${INSTALL_DATA} ${WRKSRC}/src/${i} ${PREFIX}/share/doc/ucspi-ssl
.	endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
