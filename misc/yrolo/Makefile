# $NetBSD: Makefile,v 1.21 2011/12/22 07:55:01 marino Exp $
#

DISTNAME=	yrolo-1.1
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www.muquit.com/muquit/software/yrolo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/yrolo/yrolo.html
COMMENT=	Contact management software

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/yrolo1.1
USE_IMAKE=	yes
LDFLAGS+=	-lX11

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
