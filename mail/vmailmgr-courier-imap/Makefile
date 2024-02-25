# $NetBSD: Makefile,v 1.1 2024/02/25 12:09:23 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-courier-imap-${VERSION}
CATEGORIES=		mail security

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (Courier authentication)
LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-courier-imap

BUILD_DIRS=		lib authenticate
INSTALL_DIRS=		authenticate
INSTALL_TARGET=		install-authlibPROGRAMS

.include "../../mk/bsd.pkg.mk"
