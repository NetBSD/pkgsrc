# $NetBSD: Makefile,v 1.4 1999/08/30 08:17:29 rh Exp $
# FreeBSD Id: Makefile,v 1.6 1998/08/07 23:56:12 asami Exp
#

DISTNAME=	tkhylafax-3.1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/contrib/tkhylafax/ \
		ftp://ftp.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/ \
		http://gd.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.elgro.demon.co.uk/resources.html

DEPENDS+=	hylafax-4.1b2:../../comms/hylafax
RUN_DEPENDS+=	${PREFIX}/bin/wish8.0:../../x11/tk80
RUN_DEPENDS+=	${PREFIX}/bin/gs:../../print/ghostscript5
RUN_DEPENDS+=	${X11BASE}/bin/gv:../../print/gv

WRKSRC=		${WRKDIR}/tkhylafax

.include "../../mk/bsd.pkg.mk"
