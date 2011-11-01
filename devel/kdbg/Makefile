# $NetBSD: Makefile,v 1.79 2011/11/01 06:00:56 sbd Exp $

DISTNAME=	kdbg-2.2.2
PKGREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdbg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kdbg.org/
COMMENT=	Graphical User Interface around gdb using KDE
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-kde-version=3

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
