# $NetBSD: Makefile,v 1.1.1.1 1999/05/15 08:04:51 hubertf Exp $
#

DISTNAME=	gcombust-0.1.12
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.abo.fi/~jmunsin/gcombust/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/

DEPENDS+=	mkhybrid-1.12b5.2:../mkhybrid
DEPENDS+=	cdrecord-1.6.1:../cdrecord
DEPENDS+=	cdlabelgen-1.1.3:../../print/cdlabelgen
DEPENDS+=	gv-3.5.8:../../print/gv
DEPENDS+=	gtk+-1.2.2:../../x11/gtk

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
