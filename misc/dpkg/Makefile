# $NetBSD: Makefile,v 1.47 2018/08/31 13:58:44 adam Exp $

DISTNAME=	dpkg_1.18.25
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.debian.org/Teams/Dpkg
COMMENT=	Package maintenance system for Debian
LICENSE=	gnu-gpl-v2

DEPENDS+=	patch-[0-9]*:../../devel/patch
BUILD_DEPENDS+=	po4a-[0-9]*:../../textproc/po4a
TEST_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DEFS+=	VARBASE

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt perl:run gtar:run pod2man
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-admindir=${VARBASE}/db/dpkg
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg
CONFIGURE_ARGS.Darwin+=	--enable-linker-optimizations=no
CONFIGURE_ENV+=		PATCH=${PREFIX}/bin/gpatch
TEST_TARGET=		check
INCOMPAT_CURSES+=	NetBSD-[0-5].*-*

REPLACE_PERL=		scripts/*.pl

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
PERL5_CONFIGURE=	no
.include "../../lang/perl5/module.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# override the default
CONFIGURE_ENV+=		TAR=${GTAR:Q}
