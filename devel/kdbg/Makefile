# $NetBSD: Makefile,v 1.55 2006/01/24 07:32:02 wiz Exp $

DISTNAME=	kdbg-1.2.10
PKGREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdbg/} \
		ftp://ftp.eudaptics.com/pub/people/jsixt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html
COMMENT=	Graphical User Interface around gdb using KDE

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-kde-version=3

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
