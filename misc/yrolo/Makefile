# $NetBSD: Makefile,v 1.23 2014/06/29 05:45:57 dholland Exp $
#

DISTNAME=	yrolo-1.1
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.muquit.com/muquit/software/yrolo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/yrolo/yrolo.html
COMMENT=	Contact management software

WRKSRC=		${WRKDIR}/yrolo1.1
USE_IMAKE=	yes
LDFLAGS+=	-lX11

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
