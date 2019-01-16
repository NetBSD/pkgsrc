# $NetBSD: Makefile,v 1.23 2019/01/16 18:28:03 dholland Exp $

DISTNAME=	posh_0.12.6
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
PKG_SHELL=		bin/posh
WRKSRC=			${WRKDIR}/${PKGBASE}

# Requires GNU getopt to work properly; otherwise, will build but not run
# correctly.
BROKEN_ON_PLATFORM=	NetBSD-*-* SunOS-*-*

INSTALLATION_DIRS=	share/doc/posh

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
