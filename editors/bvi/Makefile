# $NetBSD: Makefile,v 1.14 2003/07/17 21:34:21 grant Exp $
#

DISTNAME=	bvi-1.3.0.src
PKGNAME=	bvi-1.3.0
PKGREVISION=			1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH}

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
