# $NetBSD: Makefile,v 1.1.1.1 2007/09/20 20:02:53 jlam Exp $

DISTNAME=	mozilla-rootcerts-1.0.${CERTDATA_DATE}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	${CERTDATA}
EXTRACT_SUFX=	# empty

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://lxr.mozilla.org/mozilla/source/security/nss/lib/ckfw/builtins/certdata.txt?raw=1
COMMENT=	root CA certificates from the Mozilla Project

USE_TOOLS=	awk:run echo:run expr:run ln:run ls:run openssl:run rm:run

CERTDATA_DATE=	20070713
CERTDATA=	certdata-${CERTDATA_DATE}.txt

WRKSRC=		${WRKDIR}
BUILD_DIRS=	# empty
DATADIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES=		paths
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_STAGE.paths=	post-configure
SUBST_FILES.paths=	mozilla-rootcerts.sh
SUBST_VARS.paths=	AWK ECHO EXPR LN LS OPENSSL RM DATADIR

INSTALLATION_DIRS=	sbin ${DATADIR}

do-extract:
	${CP} ${FILESDIR}/mozilla-rootcerts.sh ${WRKSRC}
	${CP} ${DISTDIR}/${CERTDATA} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mozilla-rootcerts.sh \
		${PREFIX}/sbin/mozilla-rootcerts
	${INSTALL_DATA} ${WRKSRC}/${CERTDATA} ${DATADIR}/certdata.txt

.include "../../mk/bsd.pkg.mk"
