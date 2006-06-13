# $NetBSD: Makefile,v 1.62 2006/06/13 12:11:44 markd Exp $

DISTNAME=	kdbg-2.0.4
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

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
