# $NetBSD: Makefile,v 1.7 2004/11/29 17:24:49 taca Exp $
#

DISTNAME=	AiCA-0.81
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Manage Certification Authority and PKI utilities

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=    ${.CURDIR}/INSTALL
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/AiCA

CONFDIR=	${PREFIX}/etc/AiCA
DOCDIR=		${PREFIX}/share/doc/AiCA
EXAMPLESDIR=	${PREFIX}/share/examples/AiCA

CONF_FILES+=	${EXAMPLESDIR}/aica.cnf ${CONFDIR}/aica.cnf
OWN_DIRS+=	${CONFDIR}/store ${MAKE_DIRS}

COMMANDS=	aica/aica bin/aistore bin/asn1view bin/certconv \
		bin/certreq bin/certvfy bin/certview
LIBRARIES=	libaica.a libaicrypto.a libaissl.a
DOCS=		COPYRIGHT README README.j
EXAMPLES=	lib/aica.cnf sample.csv

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
