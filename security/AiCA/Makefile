# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:44 joerg Exp $
#

DISTNAME=	AiCA-0.81
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Manage Certification Authority and PKI utilities

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS=	bin include lib certs templates ${DOCDIR} ${EXAMPLESDIR}

pre-configure:
	cd ${WRKSRC}; \
		${ECHO} >> aicrypto/ecdsa/Makefile.in; \
		${CP} README README.in; ${CP} README.j README.j.in

do-install:
.for f in ${LIBRARIES}
	${INSTALL_LIB} ${WRKSRC}/lib/${f} ${DESTDIR}${PREFIX}/lib
.endfor
.for f in ${COMMANDS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/newca.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/aicrypto/include/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/aiconfig.h ${DESTDIR}${PREFIX}/include
	${CP} ${WRKSRC}/certs/*  ${DESTDIR}${PREFIX}/certs
	${CP} ${WRKSRC}/templates/*  ${DESTDIR}${PREFIX}/templates
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EXAMPLESDIR}
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
