# $NetBSD: Makefile,v 1.22 2012/10/08 09:57:42 asau Exp $
#

DISTNAME=	yrolo-1.1
PKGREVISION=	5
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
