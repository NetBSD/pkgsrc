# $NetBSD: Makefile,v 1.4 2003/01/03 15:26:59 jmmv Exp $

DISTNAME=	seahorse-0.5.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://seahorse.sourceforge.net
COMMENT=	GnuPG front end and bonobo component for Gnome

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_BUILDLINK2=	yes

DEPENDS+=	gnupg>=1.0:../../security/gnupg

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
