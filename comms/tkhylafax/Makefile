# $NetBSD: Makefile,v 1.6 2000/04/10 00:03:19 jlam Exp $
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
DEPENDS+=	tk-8.0.5:../../x11/tk80
DEPENDS+=	gv-3.5.8:../../print/gv

WRKSRC=		${WRKDIR}/tkhylafax

.include "../../mk/bsd.pkg.mk"
