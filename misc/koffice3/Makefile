# $NetBSD: Makefile,v 1.1.1.1 2002/06/20 19:31:21 jschauma Exp $

DISTNAME=       koffice
PKGNAME=        koffice3-${VERSION}          
MASTER_SITES=   ftp://ftp.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.us.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/ \
                ftp://ftp.de.kde.org/pub/kde/stable/koffice-1.1.1-kde3/src/
DISTFILES=      ${DISTNAME}-${VERSION}-kde3.tar.bz2
 
.include "../../x11/kde3/Makefile.kde3"

MAINTAINER=     jschauma@netbsd.org

WRKSRC= ${WRKDIR}/${DISTNAME}-${VERSION}
PATCHDIR=       ../../misc/koffice/patches
DESCR_SRC=      ../../misc/koffice/DESCR
  
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../misc/koffice/Makefile.common"
