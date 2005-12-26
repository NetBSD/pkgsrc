# $NetBSD: Makefile,v 1.13 2005/12/26 23:39:33 schmonz Exp $
#

DISTNAME=       yrolo-1.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=   http://www.muquit.com/muquit/software/yrolo/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/yrolo/yrolo.html
COMMENT=	Contact management software

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

WRKSRC=		${WRKDIR}/yrolo1.1
USE_IMAKE=	yes

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
