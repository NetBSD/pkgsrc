# $NetBSD: Makefile,v 1.13 2002/09/20 19:29:27 jlam Exp $

.include "../koffice/Makefile.common"

DISTNAME=	koffice-${VERSION}
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1/src/

MAINTAINER=	jschauma@netbsd.org

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	# defined

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
