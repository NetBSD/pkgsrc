# $NetBSD: Makefile,v 1.3 1997/10/15 17:11:46 agc Exp $
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

.if defined(MANZ)
MAKE_ENV +=	"COMPRESSMANCMD=${GZIP_CMD}"
.else
MAKE_ENV +=	COMPRESSMANCMD=:
.endif

pre-configure:
	find ${WRKDIR} -type f -print|xargs grep -l '/usr/local' > ${WRKDIR}/prefix-list
	for f in `cat ${WRKDIR}/prefix-list`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone && mv $$f.pdone $$f; \
	done
	rm ${WRKDIR}/prefix-list

.include <bsd.port.mk>
