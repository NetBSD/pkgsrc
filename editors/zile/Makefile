# $NetBSD: Makefile,v 1.33 2017/01/04 11:48:24 roy Exp $

DISTNAME=	zile-2.4.5
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	http://ftp.gnu.org/gnu/zile/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/zile/
COMMENT=	Emacs-like text editor
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	makeinfo
GNU_CONFIGURE=	yes

INFO_FILES=	yes

# we only want the charset.alias file, so no buildlinkery for libiconv
DEPENDS+=       libiconv-[0-9]*:../../converters/libiconv
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
