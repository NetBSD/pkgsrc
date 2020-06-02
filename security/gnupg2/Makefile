# $NetBSD: Makefile,v 1.114 2020/06/02 08:24:40 adam Exp $

DISTNAME=	gnupg-2.2.20
PKGNAME=	${DISTNAME:S/gnupg-/gnupg2-/}
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/
MASTER_SITES+=	http://mirrors.dotsrc.org/gcrypt/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@netbsdfr.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	GnuPG with OpenPGP and S/MIME capabilities
LICENSE=	gnu-gpl-v3

DEPENDS+=	pinentry-[0-9]*:../../security/pinentry

CONFLICTS+=	dirmngr-[0-9]*
SUPERSEDES+=	dirmngr-[0-9]*

BUILD_DEFS+=		VARBASE
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config makeinfo
USE_LIBTOOL=		yes
INFO_FILES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ntbtls
CONFIGURE_ARGS+=	--enable-g13
CONFIGURE_ARGS+=	--enable-gpg-is-gpg2
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
# SunOS does have getaddrinfo() and the code knows how to use it
CONFIGURE_ARGS.SunOS+=	ac_cv_func_getaddrinfo=yes

TEST_TARGET=		check

LDFLAGS.NetBSD+=	-lintl
LDFLAGS.Darwin+=	-lintl -lresolv
LDFLAGS.FreeBSD+=	-lintl
LDFLAGS.SunOS+=		-lintl -lsocket

.include "options.mk"

BUILDLINK_API_DEPENDS.sqlite3+=		sqlite3>=3.7.15
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.npth+=		npth>=1.2
.include "../../devel/npth/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.7
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.28
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.5.1
.include "../../security/libassuan2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libksba+=		libksba>=1.3.4
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
