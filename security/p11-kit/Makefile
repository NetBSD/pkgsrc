# $NetBSD: Makefile,v 1.35 2024/01/26 03:15:16 riastradh Exp $

DISTNAME=	p11-kit-0.25.3
CATEGORIES=	security
MASTER_SITES+=	${MASTER_SITE_GITHUB:=p11-glue/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://p11-glue.freedesktop.org/p11-kit.html
COMMENT=	PKCS\#11 module manager
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${BUILDLINK_API_DEPENDS.libtasn1:=:../../security/libtasn1}

DEPENDS+=	mozilla-rootcerts>=1.0.20150804nb1:../../security/mozilla-rootcerts

MESON_ARGS+=	-Dtrust_paths=${PREFIX}/share/mozilla-rootcerts/cacert.pem

USE_CC_FEATURES=	c99
USE_FEATURES+=		strndup strnlen
USE_LANGUAGES=		c
USE_TOOLS+=		msgfmt pkg-config readlink

# dirfd(3)
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# reallocarray(3)
CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS -D__EXTENSIONS__
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
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/pkcs11/pkcs11.conf.example \
		${DESTDIR}${PREFIX}/share/examples/p11-kit

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
