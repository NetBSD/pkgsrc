# $NetBSD: Makefile,v 1.2 2001/12/15 22:04:18 dmcmahill Exp $
#

DISTNAME=	gerbv-0.0.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://gerbv.sourceforge.net
COMMENT=	Gerber file viewer

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

DEPENDS+=	guile>=1.4:../../lang/guile

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
