# $NetBSD: Makefile,v 1.24.12.1 2026/11/11 13:15:48 maya Exp $
#

DISTNAME=	adodb-${VERS}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ADOdb/}
GITHUB_PROJECT=	ADOdb
GITHUB_TAG=	v${VERS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ADOdb/ADOdb
COMMENT=	Active Data Objects Data Base for php
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

VERS=		5.22.12

WRKSRC=		${WRKDIR}/ADOdb-${VERS}
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	pax

PHP_VERSIONS_ACCEPTED=	74 82 83 84 85

INSTALLATION_DIRS+=	share/adodb share/doc/adodb

do-install:
	${FIND} ${WRKSRC} -name '*.*' -type f -print | \
		${XARGS} ${CHMOD} ${SHAREMODE}
	cd ${WRKSRC}/docs && pax -rw -pmp . ${DESTDIR}${PREFIX}/share/doc/adodb
	cd ${WRKSRC} && \
		pax -rw -pmp *.php *.dtd datadict drivers lang perf \
			session xsl ${DESTDIR}${PREFIX}/share/adodb


.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
