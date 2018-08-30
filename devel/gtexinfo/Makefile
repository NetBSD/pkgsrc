# $NetBSD: Makefile,v 1.100 2018/08/30 11:27:48 tnn Exp $

DISTNAME=		texinfo-6.5
PKGNAME=		g${DISTNAME}
PKGREVISION=		3
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
CONFIGURE_ARGS+=	--with-external-libintl-perl
CONFIGURE_ARGS+=	--with-external-Text-Unidecode
CONFIGURE_ARGS+=	--with-external-Unicode-EastAsianWidth
USE_LIBTOOL=		yes

INFO_FILES=		yes
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST
USE_TOOLS+=		perl:run

PKGSRC_INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
MAKE_ENV+=		PKGSRC_INFOPATH=${PKGSRC_INFOPATH:Q}

REPLACE_SH+=		util/texi2dvi

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../lang/perl5/buildlink3.mk"	 # for EXTERN.h in XSParagraph
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
