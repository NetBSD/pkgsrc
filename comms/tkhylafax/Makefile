# $NetBSD: Makefile,v 1.12 2001/05/05 19:51:13 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1998/08/07 23:56:12 asami Exp
#

DISTNAME=	tkhylafax-3.1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/contrib/tkhylafax/ \
		ftp://ftp.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/ \
		http://gd.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.elgro.demon.co.uk/resources.html
COMMENT=	Tcl/tk interface to Sam Leffler's fax package

DEPENDS+=	hylafax-4.1b3:../../comms/hylafax
DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	gv-3.5.8:../../print/gv

WRKSRC=		${WRKDIR}/tkhylafax

.include "../../mk/bsd.pkg.mk"
