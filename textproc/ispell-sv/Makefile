# $NetBSD: Makefile,v 1.4 2023/12/22 18:22:41 zafer Exp $
#

DISTNAME=	iswedish-1.2.1
PKGNAME=	${DISTNAME:S/wedish/pell-sv/1}
CATEGORIES=	textproc
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/ispell/ispell.html
COMMENT=	Swedish dictionary for interactive spelling checker

CONFLICTS+=		ispell-svenska-[0-9]*
INSTALLATION_DIRS=	lib

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

.include "../../mk/bsd.pkg.mk"
