# $NetBSD: Makefile,v 1.1.1.1 2003/03/31 20:58:41 jmmv Exp $
#

DISTNAME=	lmule-1.1.13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmule/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://lmule.sourceforge.net/
COMMENT=	eDonkey2000 client based on eMule

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.1:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--without-included-gettext

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
