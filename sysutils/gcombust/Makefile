# $NetBSD: Makefile,v 1.16 2000/05/31 13:01:26 rh Exp $
#

DISTNAME=	gcombust-0.1.33
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
