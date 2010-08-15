# $NetBSD: Makefile,v 1.2 2010/08/15 02:31:53 obache Exp $
#

DISTNAME=	cproto-4.7i
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cproto/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://invisible-island.net/cproto/
COMMENT=	Generates function prototypes from C source

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	yacc lex

.include "../../mk/bsd.pkg.mk"
