# $NetBSD: Makefile,v 1.11 2002/06/20 19:13:50 jschauma Exp $

DISTNAME=	koffice-${VERSION}
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1/src/

.include "../../x11/kde2/Makefile.kde2"

MAINTAINER=	jschauma@netbsd.org

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../misc/koffice/Makefile.common"
