# $NetBSD: Makefile,v 1.1 2024/02/25 12:09:21 schmonz Exp $

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
DEPENDS+=	php-vmailmgr>=${VERSION}:../../mail/php-vmailmgr
DEPENDS+=	py-vmailmgr>=${VERSION}:../../mail/py-vmailmgr

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
