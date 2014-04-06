# $NetBSD: Makefile,v 1.1 2014/04/06 16:14:16 jakllsch Exp $

DISTNAME=	GenFw-r15188
PKGNAME=	GenFw-0pre15188
CATEGORIES=	cross devel sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL:=GenFw/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jakllsch@NetBSD.org
HOMEPAGE=	http://sourceforge.net/apps/mediawiki/tianocore/index.php?title=Edk2-buildtools
COMMENT=	Convert ELF to PE-COFF for UEFI
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/GenFw

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GenFw ${DESTDIR}${PREFIX}/bin/GenFw

.include "../../mk/bsd.pkg.mk"
