# $NetBSD: Makefile,v 1.1.1.1 2012/02/03 14:43:12 drochner Exp $
#

DISTNAME=	p11-kit-0.10
CATEGORIES=	security
MASTER_SITES=	http://p11-glue.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://p11-glue.freedesktop.org/
COMMENT=	PKCS#11 module manager
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	p11-kit/p11-kit-1.pc.in

PKG_SYSCONFSUBDIR= pkcs11
CONF_FILES+=	share/examples/p11-kit/pkcs11.conf.example \
		${PKG_SYSCONFDIR}/pkcs11.conf

.include "../../mk/bsd.pkg.mk"
