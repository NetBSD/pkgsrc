# $NetBSD: Makefile,v 1.11 2007/11/30 21:55:09 wiz Exp $
#

DISTNAME=		kmemaid-0.4.7.0
PKGREVISION=		7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=memaid/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://memaid.sourceforge.net/
COMMENT=		MemAid flash card program (KDE interface)

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
