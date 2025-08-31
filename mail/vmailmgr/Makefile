# $NetBSD: Makefile,v 1.4 2025/08/31 14:00:58 taca Exp $

.include "../../mail/vmailmgr/version.mk"

PKGNAME=	vmailmgr-${VERSION}
PKGREVISION=	2
CATEGORIES=	mail

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://untroubled.org/vmailmgr/
COMMENT=	Virtual domain manager for qmail
LICENSE=	gnu-gpl-v2

DEPENDS+=	vmailmgr-base>=${VERSION}:../../mail/vmailmgr-base
DEPENDS+=	vmailmgr-cgi>=${VERSION}:../../mail/vmailmgr-cgi
DEPENDS+=	vmailmgr-courier-imap>=${VERSION}:../../mail/vmailmgr-courier-imap
DEPENDS+=	vmailmgr-docs>=${VERSION}:../../mail/vmailmgr-docs
DEPENDS+=	${PHP_PKG_PREFIX}-vmailmgr>=${VERSION}:../../mail/php-vmailmgr
DEPENDS+=	${PYPKGPREFIX}-vmailmgr>=${VERSION}:../../mail/py-vmailmgr

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
