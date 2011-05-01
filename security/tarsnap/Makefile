# $NetBSD: Makefile,v 1.2 2011/05/01 08:28:24 wiz Exp $
#

DISTNAME=	tarsnap-autoconf-1.0.29
PKGNAME=	${DISTNAME:S/-autoconf//}
CATEGORIES=	security archivers sysutils
MASTER_SITES=	https://www.tarsnap.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.tarsnap.com/
COMMENT=	Secure online backup service
LICENSE=	tarsnap-license

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples/tarsnap

CONF_FILES=	${PREFIX}/share/examples/tarsnap/tarsnap.conf.sample ${PKG_SYSCONFDIR}/tarsnap.conf

.include "../../mk/bsd.pkg.mk"
