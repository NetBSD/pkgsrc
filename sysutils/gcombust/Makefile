# $NetBSD: Makefile,v 1.19 2000/10/15 12:22:45 rh Exp $
#

DISTNAME=	gcombust-0.1.35
CATEGORIES=	x11 sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/

DEPENDS+=	mkhybrid-*:../mkhybrid
DEPENDS+=	cdrecord>=1.9:../cdrecord
DEPENDS+=	cdlabelgen-*:../../graphics/cdlabelgen
DEPENDS+=	gv-*:../../print/gv
DEPENDS+=	gtk+>=1.2.4:../../x11/gtk

CONFLICTS=	cdrecord-1.9a*	# won't work with old alpha versions

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
