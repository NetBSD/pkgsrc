# $NetBSD: Makefile,v 1.11 2020/11/17 12:14:17 adam Exp $

DISTNAME=	EasyRSA-3.0.8
PKGNAME=	${DISTNAME:S/EasyRSA/easy-rsa/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVPN/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVPN/easy-rsa
COMMENT=	CLI utility to build and manage a PKI CA
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix//}

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

EASYRSA_CNF_FILES=	openssl-easyrsa.cnf vars x509-types/COMMON
EASYRSA_CNF_FILES+=	x509-types/ca x509-types/client x509-types/code-signing
EASYRSA_CNF_FILES+=	x509-types/server

INSTALLATION_DIRS+=	bin share/doc/easyrsa share/examples/easyrsa/x509-types
EGDIR=			${PREFIX}/share/examples/easyrsa
PKG_SYSCONFSUBDIR=	easyrsa
OWN_DIRS=		${PKG_SYSCONFDIR}/x509-types
.for f in ${EASYRSA_CNF_FILES}
REQD_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	pre-install
SUBST_FILES.sysconf=	easyrsa vars.example
SUBST_SED.sysconf=	-e "s|@SYSCONFDIR@|${PKG_SYSCONFDIR}|"

do-install:
	${LN} -f ${WRKSRC}/vars.example ${WRKSRC}/vars
	${INSTALL_SCRIPT} ${WRKSRC}/easyrsa ${DESTDIR}${PREFIX}/bin/easyrsa
	${INSTALL_DATA} ${WRKSRC}/*.md ${DESTDIR}${PREFIX}/share/doc/easyrsa/
	${INSTALL_DATA} ${WRKSRC}/doc/*.md ${DESTDIR}${PREFIX}/share/doc/easyrsa/
.for f in ${EASYRSA_CNF_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EGDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
