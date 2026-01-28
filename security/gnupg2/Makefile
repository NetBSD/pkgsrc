# $NetBSD: Makefile,v 1.170 2026/01/28 14:58:33 wiz Exp $

DISTNAME=	gnupg-2.5.17
PKGNAME=	${DISTNAME:S/gnupg-/gnupg2-/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=gnupg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	GnuPG with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

DEPENDS+=	pinentry-[0-9]*:../../security/pinentry

CONFLICTS+=	dirmngr-[0-9]*
SUPERSEDES+=	dirmngr-[0-9]*
CONFLICTS+=	gnupg<1.4.23nb28

BUILD_DEFS+=		VARBASE
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config makeinfo
USE_LIBTOOL=		yes
INFO_FILES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ntbtls
CONFIGURE_ARGS+=	--disable-tpm2d
CONFIGURE_ARGS+=	--enable-g13
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
# SunOS does have getaddrinfo() and the code knows how to use it
CONFIGURE_ARGS.SunOS+=	ac_cv_func_getaddrinfo=yes

TEST_TARGET=		check

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600	# socklen_t

LDFLAGS.Darwin+=	-lintl
#LDFLAGS.SunOS+=	-lsocket -lrt
#LDFLAGS.Linux+=	-lrt

# self test problems:
# https://dev.gnupg.org/T8065

.include "options.mk"

BUILDLINK_API_DEPENDS.sqlite3+=		sqlite3>=3.27.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.npth+=		npth>=1.2
.include "../../devel/npth/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.11.0
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.56
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=3.0.0
.include "../../security/libassuan2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.6.3
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
