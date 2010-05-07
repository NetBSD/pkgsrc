# $NetBSD: Makefile,v 1.12 2010/05/07 12:02:44 jmmv Exp $
#

DISTNAME=	posh_0.3.14
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
PKG_SHELL=		bin/posh
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/doc/posh

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
