# $NetBSD: Makefile,v 1.2 2002/10/05 02:54:22 wiz Exp $
#

DISTNAME=		aspell-.33.7.1
PKGNAME=		${DISTNAME:S/-./-0./}
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aspell/}

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
