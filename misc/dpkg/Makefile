# $NetBSD: Makefile,v 1.29 2013/06/14 11:15:16 obache Exp $
#

DISTNAME=	dpkg_1.16.10
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/dpkg/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.debian.org/Teams/Dpkg
COMMENT=	Package maintenance system for Debian
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=		po4a>=0:../../textproc/po4a

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DEFS+=	VARBASE

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake msgfmt perl:run gtar:run
USE_NCURSES=		yes	# needs tigetstr()

REPLACE_PERL=		scripts/*.pl
REPLACE_PERL+=		dselect/methods/ftp/install
REPLACE_PERL+=		dselect/methods/ftp/setup
REPLACE_PERL+=		dselect/methods/ftp/update

CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--disable-start-stop-daemon
CONFIGURE_ARGS+=	--with-admindir=${VARBASE}/db/dpkg
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/dpkg
# or uses GCC version specific warning flags unconditionally. 
CONFIGURE_ARGS+=	--disable-compiler-warnings

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-linker-optimisations=no
.endif

SUBST_CLASSES+=		tool-path
SUBST_STAGE.tool-path=	pre-build
SUBST_VARS.tool-path=	GTAR
SUBST_FILES.tool-path=	lib/dpkg/dpkg.h

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
PERL5_CONFIGURE=	no
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
