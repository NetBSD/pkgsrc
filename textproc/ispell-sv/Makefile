# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:47 rodent Exp $
#

DISTNAME=	iswedish-1.2.1
PKGNAME=	${DISTNAME:S/wedish/pell-sv/1}
CATEGORIES=	textproc
MASTER_SITES=	http://sv.sslug.dk/locale/ispell/iswedish/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	Swedish dictionary for interactive spelling checker

CONFLICTS+=		ispell-svenska-[0-9]*
INSTALLATION_DIRS=	lib

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

.include "../../mk/bsd.pkg.mk"
