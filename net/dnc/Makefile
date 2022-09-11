# $NetBSD: Makefile,v 1.5 2022/09/11 16:46:59 wiz Exp $

DISTNAME=	dnc-0.2.0
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
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
.include "../../mk/bsd.pkg.mk"
