# $NetBSD: Makefile,v 1.2 2004/07/15 20:31:45 jmmv Exp $
#

DISTNAME=	imposter-0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=imposter/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://imposter.sourceforge.net/
COMMENT=	Standalone OpenOffice presentations viewer using GTK2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
