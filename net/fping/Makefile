# $NetBSD: Makefile,v 1.1.1.1 2000/05/19 10:20:35 abs Exp $
# FreeBSD Id: ports/net/fping/Makefile,v 1.10 2000/04/20 20:18:57 mharo Exp

DISTNAME=	part01
PKGNAME=	fping-1.20
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.digital.com/pub/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.wustl.edu/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.isnet.is/pub/Usenet/Usenet.src/comp.sources.unix/v26/fping/
EXTRACT_SUFX=	.Z

MAINTAINER=	abs@netbsd.org

DIST_SUBDIR=	fping
EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | ${SED} -e '1,/Archive-Name/d' | ${SH}
NO_WRKSUBDIR=	yes

post-install:
	@strip ${PREFIX}/sbin/fping

.include "../../mk/bsd.pkg.mk"
