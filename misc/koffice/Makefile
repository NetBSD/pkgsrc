# $NetBSD: Makefile,v 1.12 2002/09/20 11:44:15 jlam Exp $

DISTNAME=	koffice-${VERSION}
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1/src/

.include "../../x11/kde2/Makefile.kde2"

MAINTAINER=	jschauma@netbsd.org

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	# defined

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../misc/koffice/Makefile.common"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
