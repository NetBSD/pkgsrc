# $NetBSD: Makefile,v 1.6 2002/10/06 03:38:58 jlam Exp $

.include "../koffice/Makefile.common"

DISTNAME=       koffice-${VERSION}
PKGNAME=        ${DISTNAME:S/^koffice/koffice3/}
PKGREVISION=	1
MASTER_SITES=   ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/
DISTFILES=      ${DISTNAME}-kde3.tar.bz2
 
.include "../../x11/kde3/Makefile.kde3"

CONFLICTS+=	kdelibs<=3.0.3nb1

MAINTAINER=     jschauma@netbsd.org

USE_BUILDLINK2=	# defined
PTHREAD_OPTS+=	require

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
