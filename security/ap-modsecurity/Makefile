# $NetBSD: Makefile,v 1.11 2014/06/10 15:22:14 joerg Exp $
#

DISTNAME=	modsecurity-apache_1.9.4
PKGNAME=	${APACHE_PKG_PREFIX}-modsecurity-1.9.4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

USE_TOOLS+=	pax

# does not compile with apache24
PKG_APACHE_ACCEPTED=	apache22

.include "../../mk/apache.mk"

APACHE_DIR=	apache2
MOD_EXTN=	la

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"

do-build:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH:Q} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} -c mod_security.c

INSTALLATION_DIRS+=	lib/httpd

do-install:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH:Q} \
		${APXS} -i -S LIBEXECDIR=${DESTDIR}${PREFIX}/lib/httpd mod_security.${MOD_EXTN}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/ap-security
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/ap-security

	${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-minimal \
		${DESTDIR}${PREFIX}/share/examples/ap-security
	cd ${WRKSRC}/doc && pax -rw . ${DESTDIR}${PREFIX}/share/doc/ap-security

.include "../../mk/bsd.pkg.mk"
