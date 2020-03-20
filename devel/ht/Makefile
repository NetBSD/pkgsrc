# $NetBSD: Makefile,v 1.19 2020/03/20 11:57:26 nia Exp $
#

DISTNAME=	ht-2.1.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hte/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hte.sourceforge.net/
COMMENT=	Viewer, editor and analyzer for text, binary and executable files

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++03
USE_TOOLS+=		bison lex
USE_NCURSES=		yes # missing WA_BOLD and WA_NORMAL

LIBS+=			-lm

.include "../../devel/ncurses/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
