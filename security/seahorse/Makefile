# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:59:27 jlam Exp $

DISTNAME=	seahorse-0.5.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seahorse/}

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://seahorse.sourceforge.net
COMMENT=	GnuPG front end and bonobo component for Gnome

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DEPENDS+=	gnupg>=1.0:../../security/gnupg

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
