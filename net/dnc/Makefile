# $NetBSD: Makefile,v 1.7 2023/08/14 05:24:58 wiz Exp $

DISTNAME=	dnc-0.2.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	dnc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/dnc/
COMMENT=	CLI tool to check domain names configuration
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-prettytable-[0-9]*:../../textproc/py-prettytable

PYTHON_VERSIONS_INCOMPATIBLE=	27

NO_BUILD=	yes

REPLACE_PYTHON=	dnc

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${RUN}${INSTALL_SCRIPT} ${WRKSRC}/dnc ${DESTDIR}${PREFIX}/bin
	${RUN}${INSTALL_MAN} ${WRKSRC}/dnc.1 \
	                     ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
