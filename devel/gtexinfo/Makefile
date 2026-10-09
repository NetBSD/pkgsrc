# $NetBSD: Makefile,v 1.134 2026/10/09 12:03:41 tnn Exp $

DISTNAME=	texinfo-7.3
PKGNAME=	g${DISTNAME}
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=texinfo/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/texinfo/texinfo.html
COMMENT=	GNU info documentation utilities
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
# otherwise, package installs copies of them itself
DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl
DEPENDS+=	p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode
DEPENDS+=	p5-Unicode-EastAsianWidth-[0-9]*:../../converters/p5-Unicode-EastAsianWidth

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-external-libintl-perl
CONFIGURE_ARGS+=	--with-external-Text-Unidecode
CONFIGURE_ARGS+=	--with-external-Unicode-EastAsianWidth
CONFIGURE_ARGS+=	--enable-perl-xs
CONFIGURE_ARGS+=	PERL_EXT_CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	PERL_EXT_LDFLAGS=${LDFLAGS:Q}
# embedded into texindex
CONFIGURE_ARGS+=	ac_cv_path_TI_AWK=${AWK:Q}
# Upstream insists on enforcing GNU iconv on macOS.
CONFIGURE_ENV.Darwin+=	am_cv_func_iconv_works=yes

INFO_FILES=		yes
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST

# Replace deeply nested config.sub files (in vendored perl libraries)
OVERRIDE_DIRDEPTH=	4

PKGSRC_INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${PREFIX}/${PKGINFODIR}
MAKE_ENV+=		PKGSRC_INFOPATH=${PKGSRC_INFOPATH:Q}
CPPFLAGS+=		-DPKGSRC_INFOPATH=\"${PKGSRC_INFOPATH}\"

REPLACE_SH+=		util/texi2dvi

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
# for EXTERN.h in XSParagraph
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
