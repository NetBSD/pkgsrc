# $NetBSD: Makefile,v 1.9 2011/04/15 08:34:00 obache Exp $
#

DISTNAME=	scamper-cvs-20100517
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Dual-stack traceroute software

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES+=	inet6

INSTALLATION_DIRS=bin

MAKE_FLAGS+=	WITH_DEBUG=yes	# recommended by the the software developer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scamper ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
