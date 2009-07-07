# $NetBSD: Makefile,v 1.9 2009/07/07 21:52:41 joerg Exp $
#

DISTNAME=	francais-IREQ-1.4
PKGNAME=	ispell-francais-1.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.robot.ireq.ca/pub/ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/ispell/ispell.html
COMMENT=	French dictionary for interactive spelling checker

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

INSTALLATION_DIRS=	lib

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.pkg.mk"
