# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 12:14:02 agc Exp $
#

DISTNAME=	francais-IREQ-1.4
PKGNAME=	ispell-francais-1.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.robot.ireq.ca/pub/ispell/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	French dictionary for interactive spelling checker

DEPENDS+=	ispell-base-3.1.20:../../textproc/ispell-base

CONFLICTS+=	ispell-[0-9]*

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.pkg.mk"
