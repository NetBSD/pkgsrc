# $NetBSD: Makefile,v 1.42 2024/04/04 16:42:19 ktnb Exp $

DISTNAME=	zile-2.6.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=zile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/zile/
COMMENT=	Emacs-like text editor
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man
TOOL_DEPENDS+=	p5-Locale-Msgfmt-[0-9]*:../../devel/p5-Locale-Msgfmt

USE_TOOLS+=		pkg-config perl gmake makeinfo

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-silent-rules

INFO_FILES=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
