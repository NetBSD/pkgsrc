# $NetBSD: Makefile,v 1.18 2024/02/10 16:39:00 wiz Exp $

DISTNAME=	libidn2-2.3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libidn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libidn/
COMMENT=	Convert internationalized domain names to/from ASCII Encoding
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libidn2.pc.in
INFO_FILES=		yes
TEST_TARGET=		check

# XXX: Kludge to avoid uncoditionally pick up some gtkdoc-* tools if gtk-doc
# XXX: package is installed and then fails in the installation phase.
CONFIGURE_ENV+=	ac_cv_prog_GTKDOC_CHECK=
CONFIGURE_ENV+=	ac_cv_path_GTKDOC_CHECK_PATH=
CONFIGURE_ENV+=	ac_cv_path_GTKDOC_REBASE=
CONFIGURE_ENV+=	ac_cv_path_GTKDOC_MKPDF=

.include "../../mk/bsd.prefs.mk"

.if ${PKGSRC_COMPILER:Msunpro}
# configure check passes, but linker will fail during build
post-configure:
	${ECHO} '#undef HAVE_SYMVER_ALIAS_SUPPORT' >> ${WRKSRC}/config.h
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
