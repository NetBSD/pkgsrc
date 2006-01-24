# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:32 wiz Exp $
#

DISTNAME=	modsecurity-1.8.7
PKGNAME=	ap-modsecurity-1.8.7
PKGREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.modsecurity.org/
COMMENT=	Intrusion detection and prevention engine for web applications

.include "../../mk/apache.mk"

.if ${PKG_APACHE} == "apache2"
APACHE_DIR=	apache2
MOD_EXTN=	la
.else
APACHE_DIR=	apache1
MOD_EXTN=	so
.endif
PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"

do-build:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} -c mod_security.c

do-install:
	cd ${WRKSRC}/${APACHE_DIR} && \
		${SETENV} PATH=${PATH} \
		${APXS} ${CPPFLAGS} ${LDFLAGS} -i mod_security.${MOD_EXTN}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ap-security
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ap-security

	${INSTALL_DATA} ${WRKSRC}/httpd.conf.regression-v1 \
		${PREFIX}/share/examples/ap-security
	${INSTALL_DATA} ${WRKSRC}/httpd.conf.regression-v2 \
		${PREFIX}/share/examples/ap-security
	${INSTALL_DATA} ${WRKSRC}/httpd.conf.example-minimal \
		${PREFIX}/share/examples/ap-security
	${INSTALL_DATA} ${WRKSRC}/modsecurity-manual.pdf \
		${PREFIX}/share/doc/ap-security

.include "../../mk/bsd.pkg.mk"
