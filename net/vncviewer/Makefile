# $NetBSD: Makefile,v 1.1.1.1 2000/11/10 16:55:13 abs Exp $
# FreeBSD Id: Makefile,v 1.2 1998/03/19 01:54:59 msmith Exp
#

DISTNAME=       	vnc-3.3.3r1_unixsrc
PKGNAME=		vncviewer-3.3.3.1
CATEGORIES=		net x11
MASTER_SITES=   	http://www.uk.research.att.com/vnc/dist/
EXTRACT_SUFX=		.tgz

MAINTAINER=	 	packages@netbsd.org
HOMEPAGE=		http://www.uk.research.att.com/vnc/

CRYPTO=			yes
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/vnc_unixsrc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${MKDIR} ${PREFIX}/share/doc/vncviewer
	${INSTALL_DATA} ${WRKSRC}/vncviewer/README ${PREFIX}/share/doc/vncviewer/README

.include "../../mk/bsd.pkg.mk"
