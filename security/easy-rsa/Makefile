# $NetBSD: Makefile,v 1.5 2018/01/30 14:34:06 mef Exp $

DISTNAME=	easy-rsa-3.0.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVPN/}

COMMENT=	CLI utility to build and manage a PKI CA
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVPN/easy-rsa/
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	easy-rsa
GITHUB_TAG=	v${PKGVERSION_NOREV}
USE_LANGUAGES=	# none

EASYRSA_DOC_FILES=	COPYING.md ChangeLog KNOWN_ISSUES README.md
EASYRSA_DOC_FILES+=	README.quickstart.md

EASYRSA_CNF_FILES=	openssl-easyrsa.cnf vars.example x509-types/COMMON
EASYRSA_CNF_FILES+=	x509-types/ca x509-types/client x509-types/server

INSTALLATION_DIRS+=	${BINDIR} ${DOCDIR} ${EGDIR} # ${PKGMANDIR}/man1
BINDIR=			${PREFIX}/bin
DOCDIR=			${PREFIX}/share/doc/easyrsa
EGDIR=			${PREFIX}/share/examples/easyrsa
PKG_SYSCONFSUBDIR=	easyrsa
OWN_DIRS=		${PKG_SYSCONFDIR}/x509-types
.for f in ${EASYRSA_CNF_FILES}
REQD_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

NO_CONFIGURE=		yes
NO_BUILD=		yes

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-patch
SUBST_FILES.sysconf=	easyrsa3/easyrsa
SUBST_SED.sysconf=	-e "s|@@@SYSCONF@@@|${PKG_SYSCONFDIR}|"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/easyrsa3/easyrsa ${DESTDIR}${BINDIR}/easyrsa
#	${INSTALL_MAN} ${FILESDIR}/easyrsa.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/x509-types
.for f in ${EASYRSA_CNF_FILES}
	${INSTALL_DATA} ${WRKSRC}/easyrsa3/${f} ${DESTDIR}${EGDIR}/${f}
.endfor

.for f in ${EASYRSA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
