# $NetBSD: Makefile,v 1.24 2020/01/26 17:31:45 rillig Exp $
#

DISTNAME=	yrolo-1.1
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.muquit.com/muquit/software/yrolo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.muquit.com/muquit/software/yrolo/yrolo.html
COMMENT=	Contact management software

WRKSRC=		${WRKDIR}/yrolo1.1
USE_IMAKE=	yes
LDFLAGS+=	-lX11

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
