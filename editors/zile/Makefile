# $NetBSD: Makefile,v 1.38 2020/09/26 12:41:02 wiz Exp $

DISTNAME=	zile-2.4.14
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://ftp.gnu.org/gnu/zile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/zile/
COMMENT=	Emacs-like text editor
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config perl gmake makeinfo

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-silent-rules

INFO_FILES=		yes

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
BUILD_DEPENDS+=	p5-Locale-Msgfmt-[0-9]*:../../devel/p5-Locale-Msgfmt

# we only want the charset.alias file, so no buildlinkery for libiconv
DEPENDS+=       libiconv-[0-9]*:../../converters/libiconv
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
