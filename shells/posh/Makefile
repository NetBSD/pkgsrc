# $NetBSD: Makefile,v 1.21 2018/09/29 12:34:07 tnn Exp $
#

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

INSTALLATION_DIRS=	share/doc/posh

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
