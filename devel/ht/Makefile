# $NetBSD: Makefile,v 1.12 2010/03/17 14:22:12 joerg Exp $
#

DISTNAME=	ht-2.0.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hte/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hte.sourceforge.net/
COMMENT=	Viewer, editor and analyzer for text, binary and executable files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison lex
USE_NCURSES=		yes # missing WA_BOLD and WA_NORMAL

LIBS+=			-lm

.include "../../devel/ncurses/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
