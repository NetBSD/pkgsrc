# $NetBSD: Makefile,v 1.17 2004/01/20 12:14:05 agc Exp $
#

DISTNAME=	bvi-1.3.0.src
PKGNAME=	bvi-1.3.0
PKGREVISION=			1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
