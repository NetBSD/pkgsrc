# $NetBSD: Makefile,v 1.24 2001/03/10 11:46:52 drochner Exp $
#

DISTNAME=	gcombust-0.1.42
CATEGORIES=	x11 sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.abo.fi/~jmunsin/gcombust/
COMMENT=	Graphical frontend for CD mastering (mkhybrid, cdrecord, ...)

DEPENDS+=	cdrecord>=1.9:../cdrecord
DEPENDS+=	cdlabelgen-*:../../graphics/cdlabelgen
DEPENDS+=	gv-*:../../print/gv
DEPENDS+=	gtk+>=1.2.4:../../x11/gtk

CONFLICTS=	cdrecord-1.9a*	# won't work with old alpha versions

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES

.include "../../mk/bsd.pkg.mk"
