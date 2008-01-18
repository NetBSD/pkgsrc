# $NetBSD: Makefile,v 1.68 2008/01/18 05:14:33 tnn Exp $

DISTNAME=	kdbg-2.0.5
PKGREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdbg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kdbg.org/
COMMENT=	Graphical User Interface around gdb using KDE

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-kde-version=3

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
