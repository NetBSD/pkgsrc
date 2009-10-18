# $NetBSD: Makefile,v 1.17 2009/10/18 20:28:52 zafer Exp $
#

DISTNAME=	donkey
PKGNAME=	edonkey2k-16.16.59
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# http://www.edonkey2000.com/files/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.edonkey2000.com/
COMMENT=	Yet another P2P file sharing tool

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
