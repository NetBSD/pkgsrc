# $NetBSD: Makefile,v 1.31 2017/07/06 00:58:35 gdt Exp $

DISTNAME=	mozilla-rootcerts-1.0.${CERTDATA_DATE}
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	-https://hg.mozilla.org/mozilla-central/raw-file/052b90b5414f/security/nss/lib/ckfw/builtins/certdata.txt
DISTFILES=	${CERTDATA}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hg.mozilla.org/mozilla-central/log/tip/security/nss/lib/ckfw/builtins/certdata.txt
COMMENT=	Root CA certificates from the Mozilla Project
LICENSE=	mpl-2.0

USE_TOOLS=	awk:run echo:run expr:run ln:run ls:run openssl:run rm:run mkdir:run

# This must be kept in sync with security/mozilla-rootcerts-openssl
CERTDATA_DATE=	20170121
CERTDATA=	certdata-${CERTDATA_DATE}.txt

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/${PKGBASE}

# Set paths depending on whether we depend on builtin or pkgsrc
# openssl.  \todo Arguably, we should consider installing into both
# builtin and pkgsrc, if both exist, but this requires much more
# thought.
CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl=	no
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
SSLDIR=		/etc/openssl
.else
SSLDIR=		${PKG_SYSCONFDIR}/openssl
.endif

CERT_SCRIPT=		mozilla-rootcerts.sh

SUBST_CLASSES=		paths
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	${CERT_SCRIPT}
SUBST_VARS.paths=	AWK DATADIR ECHO EXPR LN LS MKDIR PREFIX SSLDIR RM
SUBST_SED.paths=	-e 's,@OPENSSL@,${TOOLS_PATH.openssl},g'

INSTALLATION_DIRS=	sbin ${DATADIR}

do-extract:
	${CP} ${FILESDIR}/${CERT_SCRIPT} ${WRKSRC}
	${CP} ${DISTDIR}/${CERTDATA} ${WRKSRC}

do-build:
	${MKDIR} ${WRKSRC}/certs
	cd ${WRKSRC}/certs && \
	${SH} ${WRKSRC}/${CERT_SCRIPT} -f ${WRKSRC}/${CERTDATA} extract
	${LS} -rt ${WRKSRC}/certs/*.pem | ${XARGS} ${CAT} >${WRKSRC}/cacert.pem

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${CERT_SCRIPT} \
		${DESTDIR}${PREFIX}/sbin/mozilla-rootcerts
	${INSTALL_DATA} ${WRKSRC}/${CERTDATA} ${DESTDIR}${DATADIR}/certdata.txt
	${INSTALL_DATA} ${WRKSRC}/cacert.pem ${DESTDIR}${DATADIR}/cacert.pem

.include "../../mk/bsd.pkg.mk"
