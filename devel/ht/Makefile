# $NetBSD: Makefile,v 1.5 2005/05/12 20:19:47 jmmv Exp $
#

DISTNAME=	ht-0.9.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hte/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://hte.sourceforge.net/
COMMENT=	Viewer, editor and analyzer for text, binary and executable files

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		lex yacc
USE_NCURSES=		# missing WA_BOLD and WA_NORMAL

LIBS+=			-lm

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
