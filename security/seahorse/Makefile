# $NetBSD: Makefile,v 1.3 2002/09/23 17:29:43 wiz Exp $

DISTNAME=	seahorse-0.5.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://seahorse.sourceforge.net
COMMENT=	GnuPG front end and bonobo component for Gnome

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_BUILDLINK2=	yes

DEPENDS+=	gnupg>=1.0:../../security/gnupg

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
