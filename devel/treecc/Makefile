# $NetBSD: Makefile,v 1.17 2010/07/06 10:17:12 jmmv Exp $
#

DISTNAME=	treecc-0.3.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/projects/dotgnu/
COMMENT=	DotGNU Portable.NET aspect-oriented programming tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake lex yacc makeinfo
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
