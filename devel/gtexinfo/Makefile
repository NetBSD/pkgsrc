# $NetBSD: Makefile,v 1.106 2019/10/16 21:17:08 wiz Exp $

DISTNAME=		texinfo-6.7
PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info documentation utilities
LICENSE=		gnu-gpl-v3

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man
# otherwise, package installs copies of them itself
DEPENDS+=		p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl
DEPENDS+=		p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode
DEPENDS+=		p5-Unicode-EastAsianWidth-[0-9]*:../../converters/p5-Unicode-EastAsianWidth

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # otherwise MiscXS.pm won't be installed
CONFIGURE_ARGS+=	--with-external-libintl-perl
CONFIGURE_ARGS+=	--with-external-Text-Unidecode
CONFIGURE_ARGS+=	--with-external-Unicode-EastAsianWidth
CONFIGURE_ARGS+=	PERL_EXT_CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	PERL_EXT_LDFLAGS=${LDFLAGS:Q}

USE_LIBTOOL=		yes

INFO_FILES=		yes
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST
USE_TOOLS+=		perl:run

# Replace deeply nested config.sub files (in vendored perl libraries)
OVERRIDE_DIRDEPTH=	4

PKGSRC_INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${PREFIX}/${PKGINFODIR}
MAKE_ENV+=		PKGSRC_INFOPATH=${PKGSRC_INFOPATH:Q}

REPLACE_SH+=		util/texi2dvi

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "FreeBSD"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.include "../../lang/perl5/buildlink3.mk"	 # for EXTERN.h in XSParagraph
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
