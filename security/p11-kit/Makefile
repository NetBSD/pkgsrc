# $NetBSD: Makefile,v 1.5 2017/08/24 14:50:19 jperkin Exp $
#

DISTNAME=	p11-kit-0.22.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://p11-glue.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://p11-glue.freedesktop.org/p11-kit.html
COMMENT=	PKCS#11 module manager
LICENSE=	modified-bsd

DEPENDS=	mozilla-rootcerts>=1.0.20150804nb1:../../security/mozilla-rootcerts

CONFIGURE_ARGS+=	--with-trust-paths=${PREFIX}/share/mozilla-rootcerts/cacert.pem

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

# dirfd(3)
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=	-lsocket -lnsl

PKGCONFIG_OVERRIDE+=	p11-kit/p11-kit-1.pc.in

PKG_SYSCONFSUBDIR= pkcs11
CONF_FILES+=	share/examples/p11-kit/pkcs11.conf.example \
		${PKG_SYSCONFDIR}/pkcs11.conf

.include "../../devel/libffi/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
