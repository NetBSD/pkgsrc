# $NetBSD: Makefile,v 1.12 2013/03/15 16:14:55 bsiegert Exp $

DISTNAME=	mozilla-rootcerts-1.0.${CERTDATA_DATE}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${CERTDATA}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mxr.mozilla.org/mozilla/source/security/nss/lib/ckfw/builtins/certdata.txt?raw=1
COMMENT=	Root CA certificates from the Mozilla Project
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

USE_TOOLS=	awk:run echo:run expr:run ln:run ls:run openssl:run rm:run mkdir:run

CERTDATA_DATE=	20121229
CERTDATA=	certdata-${CERTDATA_DATE}.txt

WRKSRC=		${WRKDIR}
BUILD_DIRS=	# empty
DATADIR=	${PREFIX}/share/${PKGBASE}

CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/builtin.mk"
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
SSLDIR=		/etc/openssl/certs
.else
SSLDIR=		${PKG_SYSCONFDIR}/openssl/certs
.endif

SUBST_CLASSES=		paths
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	mozilla-rootcerts.sh
SUBST_VARS.paths=	AWK ECHO EXPR LN LS RM DATADIR MKDIR SSLDIR
SUBST_SED.paths=	-e 's,@OPENSSL@,${TOOLS_PATH.openssl},g'

INSTALLATION_DIRS=	sbin ${DATADIR}

do-extract:
	${CP} ${FILESDIR}/mozilla-rootcerts.sh ${WRKSRC}
	${CP} ${DISTDIR}/${CERTDATA} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla-rootcerts.sh \
		${DESTDIR}${PREFIX}/sbin/mozilla-rootcerts
	${INSTALL_DATA} ${WRKSRC}/${CERTDATA} ${DESTDIR}${DATADIR}/certdata.txt

.include "../../mk/bsd.pkg.mk"
