# $NetBSD: Makefile,v 1.4 1997/10/16 12:43:24 agc Exp $
# New ports collection makefile for:	netpbm
# Version required:	1mar1994
# Date created:		?
# Whom:			jmz (original)
#
# FreeBSD Id: Makefile,v 1.8 1996/11/18 11:28:55 asami Exp
#

DISTNAME=	netpbm
PKGNAME=	netpbm-94.3.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTFILES=	netpbm-1mar1994.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	tiff\\.3\\.:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes

OPSYS!=		uname -s

.if (${OPSYS} == "NetBSD")

MAKE_ENV +=	COMPRESSMANCMD="${GZIP_CMD}"
MANCOMPRESSED=	yes

pre-configure:
	for f in `find ${WRKDIR} -type f -print|xargs grep -l '/usr/local'`; do \
		${SED} -e 's:/usr/local:'${LOCALBASE}':g' < $$f > $$f.pdone && mv $$f.pdone $$f; \
	done
.endif

.include <bsd.port.mk>
