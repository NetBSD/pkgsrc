# $NetBSD: Makefile,v 1.1.1.1 2006/10/06 20:26:51 markd Exp $
#

DISTNAME=	gwenview-i18n-1.4.0
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwenview.sourceforge.net/
COMMENT=	Translations for gwenview image viewer

USE_TOOLS+=	gmake msgfmt
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

DEPENDS+=	gwenview-1.4.0{,nb[0-9]*}:../../graphics/gwenview

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
