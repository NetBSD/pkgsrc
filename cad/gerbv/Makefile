# $NetBSD: Makefile,v 1.3 2002/02/10 17:48:59 dmcmahill Exp $
#

DISTNAME=	gerbv-0.0.7
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
