# $NetBSD: Makefile,v 1.2 2004/08/29 14:47:07 recht Exp $
#

DISTNAME=	posh_0.3.9
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/posh/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://packages.debian.org/posh
COMMENT=	Debian Policy-compliant Ordinary SHell

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
PKG_SHELL=		${PREFIX}/bin/posh
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
WRKSRC=			${WRKDIR}/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/posh
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/posh
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/posh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/posh

.include "../../mk/bsd.pkg.mk"
