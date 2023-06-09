# $NetBSD: Makefile,v 1.1 2023/06/09 18:46:45 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.0.20150326
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=ser/}
GITHUB_PROJECT=		checkpassword-phpbb
GITHUB_TAG=		4d6e5e81cffa0550902b5dfaaa607911f87701d7

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/ser/checkpassword-phpbb/
COMMENT=		DJB-style checkpassword for phpBB MySQL userdb
LICENSE=		gnu-lgpl-v3

DEPENDS+=		${PYPKGPREFIX}-mysql-connector-[0-9]*:../../databases/py-mysql-connector
DEPENDS+=		${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt

USE_LANGUAGES=		# none
NO_BUILD=		yes
REPLACE_PYTHON+=	${PKGBASE}.py

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE}.py ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
