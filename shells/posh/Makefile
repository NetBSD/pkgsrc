# $NetBSD: Makefile,v 1.8 2005/12/29 06:22:12 jlam Exp $
#

DISTNAME=	posh_0.3.14
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
PKG_SHELL=		bin/posh
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/posh
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
