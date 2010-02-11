# $NetBSD: Makefile,v 1.7 2010/02/11 22:41:44 joerg Exp $
#

DISTNAME=	scamper-cvs-20060331
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Dual-stack traceroute software

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=bin

MAKE_FLAGS+=	WITH_DEBUG=yes	# recommended by the the software developer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scamper ${DESTDIR}${PREFIX}/bin

PKG_OPTIONS_VAR=		PKG_OPTIONS.scamper
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
