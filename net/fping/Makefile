# $NetBSD: Makefile,v 1.6 2002/02/18 18:40:41 abs Exp $
# FreeBSD Id: ports/net/fping/Makefile,v 1.10 2000/04/20 20:18:57 mharo Exp

DISTNAME=	part01
PKGNAME=	fping-1.20
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.uu.net/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.digital.com/pub/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.wustl.edu/usenet/comp.sources.unix/volume26/fping/ \
		ftp://ftp.isnet.is/pub/Usenet/Usenet.src/comp.sources.unix/v26/fping/
EXTRACT_SUFX=	.Z

MAINTAINER=	abs@netbsd.org
COMMENT=	Quickly ping many hosts w/o flooding the network

DIST_SUBDIR=	fping
EXTRACT_CMD=	zcat ${DOWNLOADED_DISTFILE} | ${SED} -e '1,/Archive-Name/d' | ${SH}
WRKSRC=		${WRKDIR}

post-install:
	${CHMOD} 4555 ${LOCALBASE}/sbin/fping

.include "../../mk/bsd.pkg.mk"
