# $NetBSD: Makefile,v 1.25 2001/09/27 23:18:42 jlam Exp $
#

DISTNAME=	gcombust-0.1.42
CATEGORIES=	x11 sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/
COMMENT=	Graphical frontend for CD mastering (mkhybrid, cdrecord, ...)

DEPENDS+=	cdrecord>=1.9:../cdrecord
DEPENDS+=	cdlabelgen-[0-9]*:../../graphics/cdlabelgen
DEPENDS+=	gv-[0-9]*:../../print/gv
DEPENDS+=	gtk+>=1.2.4:../../x11/gtk

CONFLICTS=	cdrecord-1.9a*	# won't work with old alpha versions

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
