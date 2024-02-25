# $NetBSD: Makefile,v 1.1 2024/02/25 12:09:22 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-cgi-${VERSION}
CATEGORIES=		mail www

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (cgi programs)
LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--enable-cgi

BUILD_DIRS=		lib cgi
INSTALL_DIRS=		cgi

.include "../../mk/bsd.pkg.mk"
