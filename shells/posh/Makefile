# $NetBSD: Makefile,v 1.20 2016/01/25 15:09:01 ryoon Exp $
#

DISTNAME=	posh_0.12.5
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
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/doc/posh

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/changelog ${DESTDIR}${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
