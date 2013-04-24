# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:45 rodent Exp $
#

DISTNAME=	francais-IREQ-1.4
PKGNAME=	ispell-${DISTNAME:S/francais-IREQ/fr/1}
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.robot.ireq.ca/pub/ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	French dictionary for interactive spelling checker

CONFLICTS+=	ispell-francais-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

INSTALLATION_DIRS=	lib

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.pkg.mk"
