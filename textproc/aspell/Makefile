# $NetBSD: Makefile,v 1.1.1.1 2002/01/15 01:07:25 wiz Exp $
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
USE_BUILDLINK_ONLY=	yes

# halfdelay()
USE_NCURSES=		yes

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses

.include "../../devel/ncurses/buildlink.mk"
.include "../../textproc/libpspell/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
