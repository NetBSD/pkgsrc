# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:31 jlam Exp $
#

DISTNAME=	AiCA-0.81
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Manage Certification Authority and PKI utilities

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=    ${.CURDIR}/INSTALL
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/AiCA

PKG_SYSCONFSUBDIR?=	AiCA
CONF_FILES+=		${EXAMPLESDIR}/aica.cnf ${PKG_SYSCONFDIR}/aica.cnf
OWN_DIRS+=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/store

DOCDIR=			${PREFIX}/share/doc/AiCA
EXAMPLESDIR=		${PREFIX}/share/examples/AiCA
COMMANDS=		aica/aica bin/aistore bin/asn1view bin/certconv \
			bin/certreq bin/certvfy bin/certview
LIBRARIES=		libaica.a libaicrypto.a libaissl.a
DOCS=			COPYRIGHT README README.j
EXAMPLES=		lib/aica.cnf sample.csv

INSTALLATION_DIRS=	bin include lib

pre-configure:
	cd ${WRKSRC}; \
		${ECHO} >> aicrypto/ecdsa/Makefile.in; \
		${CP} README README.in; ${CP} README.j README.j.in

do-install:
.for f in ${LIBRARIES}
	${INSTALL_LIB} ${WRKSRC}/lib/$f ${PREFIX}/lib
.endfor
.for f in ${COMMANDS}
	${INSTALL_PROGRAM} ${WRKSRC}/$f ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/newca.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/aicrypto/include/*.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/aiconfig.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/certs
	${CP} ${WRKSRC}/certs/*  ${PREFIX}/certs
	${INSTALL_DATA_DIR} ${PREFIX}/templates
	${CP} ${WRKSRC}/templates/*  ${PREFIX}/templates
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/$f ${EXAMPLESDIR}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
