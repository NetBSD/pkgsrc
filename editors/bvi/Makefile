# $NetBSD: Makefile,v 1.11 2002/10/25 17:33:59 wiz Exp $
#

DISTNAME=	bvi-1.3.0.src
PKGNAME=	bvi-1.3.0
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
