# $NetBSD: Makefile,v 1.4 2002/09/20 11:44:16 jlam Exp $

DISTNAME=       koffice
PKGNAME=        koffice3-${VERSION}          
MASTER_SITES=   ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/
DISTFILES=      ${DISTNAME}-${VERSION}-kde3.tar.bz2
 
.include "../../x11/kde3/Makefile.kde3"

MAINTAINER=     jschauma@netbsd.org
PTHREAD_OPTS+=	require

WRKSRC= ${WRKDIR}/${DISTNAME}-${VERSION}
PATCHDIR=       ../../misc/koffice/patches
DESCR_SRC=      ../../misc/koffice/DESCR

USE_BUILDLINK_ONLY=	# defined
  
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../misc/koffice/Makefile.common"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
