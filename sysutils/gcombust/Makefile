# $NetBSD: Makefile,v 1.28 2002/10/21 15:16:49 wiz Exp $
#

DISTNAME=	gcombust-0.1.49
CATEGORIES=	x11 sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/
COMMENT=	Graphical frontend for CD mastering (mkhybrid, cdrecord, ...)

DEPENDS+=	cdrecord>=1.10:../../sysutils/cdrecord
DEPENDS+=	cdlabelgen-[0-9]*:../../graphics/cdlabelgen
DEPENDS+=	gv-[0-9]*:../../print/gv

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
