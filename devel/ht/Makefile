# $NetBSD: Makefile,v 1.22 2024/05/06 08:40:23 jperkin Exp $
#

DISTNAME=	ht-2.1.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hte/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hte.sourceforge.net/
COMMENT=	Viewer, editor and analyzer for text, binary and executable files

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison lex

LIBS+=			-lm

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

.include "../../devel/ncurses/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
