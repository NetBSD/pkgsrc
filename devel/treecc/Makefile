# $NetBSD: Makefile,v 1.20 2022/11/12 09:10:23 nikita Exp $
#

DISTNAME=	treecc-0.3.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/projects/dotgnu/
COMMENT=	DotGNU Portable.NET aspect-oriented programming tool

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake lex yacc makeinfo
INFO_FILES=	yes

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
