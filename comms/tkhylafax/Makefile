# $NetBSD: Makefile,v 1.19 2002/03/17 11:19:14 rh Exp $
# FreeBSD Id: Makefile,v 1.6 1998/08/07 23:56:12 asami Exp
#

DISTNAME=	tkhylafax-3.1
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.sgi.com/sgi/fax/contrib/tkhylafax/ \
		ftp://ftp.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/ \
		http://gd.tuwien.ac.at/infosys/fax/hylafax/contrib/tkhylafax/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.elgro.demon.co.uk/resources.html
COMMENT=	Tcl/tk interface to Sam Leffler's fax package

DEPENDS+=	gv>=3.5.8nb1:../../print/gv
DEPENDS+=	hylafax>=4.1:../../comms/hylafax
DEPENDS+=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}/tkhylafax

.include "../../mk/bsd.pkg.mk"
