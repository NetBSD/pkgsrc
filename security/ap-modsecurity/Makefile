# $NetBSD: Makefile,v 1.6 2008/05/26 02:13:23 joerg Exp $
#

DISTNAME=	modsecurity-apache_1.9.4
PKGNAME=	${APACHE_PKG_PREFIX}-modsecurity-1.9.4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

USE_TOOLS+=	pax

.include "../../mk/apache.mk"

PKG_APACHE_ACCEPTED=	apache13 apache2

.if ${PKG_APACHE} == "apache2"
APACHE_DIR=	apache2
MOD_EXTN=	la
.endif

.if ${PKG_APACHE} == "apache13"
APACHE_DIR=	apache1
MOD_EXTN=	so
.endif

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"

do-build:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH:Q} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} -c mod_security.c

do-install:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH:Q} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} -i mod_security.${MOD_EXTN}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ap-security
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ap-security

	${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-minimal \
		${PREFIX}/share/examples/ap-security
	cd ${WRKSRC}/doc && pax -rw . ${PREFIX}/share/doc/ap-security

.include "../../mk/bsd.pkg.mk"
