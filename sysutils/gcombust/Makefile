# $NetBSD: Makefile,v 1.22 2001/01/05 19:59:49 rh Exp $
#

DISTNAME=	gcombust-0.1.39
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
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
