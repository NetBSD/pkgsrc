# $NetBSD: Makefile,v 1.31 2023/11/16 07:51:41 mrg Exp $

DISTNAME=	p11-kit-0.25.2
CATEGORIES=	security
#MASTER_SITES=	http://p11-glue.freedesktop.org/releases/
MASTER_SITES+=	${MASTER_SITE_GITHUB:=p11-glue/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://p11-glue.freedesktop.org/p11-kit.html
COMMENT=	PKCS\#11 module manager
LICENSE=	modified-bsd

DEPENDS+=	mozilla-rootcerts>=1.0.20150804nb1:../../security/mozilla-rootcerts

MESON_ARGS+=	-Dtrust_paths=${PREFIX}/share/mozilla-rootcerts/cacert.pem

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		pkg-config readlink
USE_FEATURES+=		strndup strnlen

# dirfd(3)
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# reallocarray(3)
CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=	-lsocket -lnsl

DLEXT.dylib=	dylib
DLEXT=		${DLEXT.${SHLIB_TYPE}:Uso}
PLIST_SUBST+=	DLEXT=${DLEXT:Q}

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/p11-kit:${WRKSRC}/output/trust

PKGCONFIG_OVERRIDE+=	p11-kit/p11-kit-1.pc.in

CONF_FILES+=		share/examples/p11-kit/pkcs11.conf.example \
			${PKG_SYSCONFDIR}/pkcs11.conf

INSTALLATION_DIRS+=	share/examples/p11-kit

post-install:
	mv ${DESTDIR}${PKG_SYSCONFDIR}/pkcs11/pkcs11.conf.example \
		${DESTDIR}${PREFIX}/share/examples/p11-kit

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
