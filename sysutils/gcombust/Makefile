# $NetBSD: Makefile,v 1.27 2002/03/16 02:24:19 rh Exp $
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
DEPENDS+=	gtk+>=1.2.4:../../x11/gtk

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
