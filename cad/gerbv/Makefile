# $NetBSD: Makefile,v 1.4 2002/05/07 00:51:17 dmcmahill Exp $
#

DISTNAME=	gerbv-0.0.8
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
