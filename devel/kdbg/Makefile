# $NetBSD: Makefile,v 1.29 2002/07/17 11:32:16 skrll Exp $

DISTNAME=	kdbg-1.2.5
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdbg/} \
		ftp://ftp.eudaptics.com/pub/people/jsixt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html
COMMENT=	Graphical User Interface around gdb using KDE

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=     YES
#AUTOMAKE_OVERRIDE=      YES

USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--with-kde-version=3

.include "../../x11/qt3-libs/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
