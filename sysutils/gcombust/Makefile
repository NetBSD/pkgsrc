# $NetBSD: Makefile,v 1.13 2000/02/19 20:08:30 rh Exp $
#

DISTNAME=	gcombust-0.1.29
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.abo.fi/~jmunsin/gcombust/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/

DEPENDS+=	mkhybrid-*:../mkhybrid
DEPENDS+=	cdrecord-*:../cdrecord
DEPENDS+=	cdlabelgen-*:../../graphics/cdlabelgen
DEPENDS+=	gv-*:../../print/gv
DEPENDS+=	gtk+>=1.2.4:../../x11/gtk

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
