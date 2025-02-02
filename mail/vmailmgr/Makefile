# $NetBSD: Makefile,v 1.2 2025/02/02 20:13:27 schmonz Exp $

.include "../../mail/vmailmgr/version.mk"

PKGNAME=	vmailmgr-${VERSION}
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
DEPENDS+=	py-vmailmgr>=${VERSION}:../../mail/py-vmailmgr

META_PACKAGE=	yes

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
