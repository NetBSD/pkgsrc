# $NetBSD: Makefile,v 1.3 2002/12/25 03:47:36 wiz Exp $
#

DISTNAME=		aspell-.33.7.1
PKGNAME=		${DISTNAME:S/-./-0./}
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aspell/}

PATCHFILES=		aspell-.33-fix2.diff
PATCH_SITES=		${MASTER_SITES}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://aspell.sourceforge.net/
COMMENT=		spell checker with good multi-language support

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=		yes

# halfdelay()
USE_NCURSES=		yes

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../textproc/libpspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
