# $NetBSD: Makefile,v 1.16 2008/03/19 11:56:46 obache Exp $
#

DISTNAME=	treecc-0.3.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.gnu.org/projects/dotgnu/
COMMENT=	DotGNU Portable.NET aspect-oriented programming tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake lex yacc makeinfo
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
