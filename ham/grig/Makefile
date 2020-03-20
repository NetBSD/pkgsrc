# $NetBSD: Makefile,v 1.55 2020/03/20 11:57:54 nia Exp $
#

DISTNAME=	grig-0.8.1
PKGREVISION=	10
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
GNU_CONFIGURE=	yes

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
