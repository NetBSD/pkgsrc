# $NetBSD: Makefile,v 1.5 2005/07/29 18:32:18 jlam Exp $
#

DISTNAME=	posh_0.3.14
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
PKG_SHELL=		bin/posh
USE_PKGINSTALL=		YES
WRKSRC=			${WRKDIR}/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/posh
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
