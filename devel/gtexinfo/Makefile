# $NetBSD: Makefile,v 1.2 1997/12/14 23:09:43 hubertf Exp $
# New ports collection makefile for:	GNU texinfo
# Version required:     3.11
# Date created:		14 November 1997
# Whom:			lamj@stat.cmu.edu
#

DISTNAME=       texinfo-3.11
PKGNAME=	gtexinfo-3.11
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	lamj@stat.cmu.edu

GNU_CONFIGURE=	yes

post-install:
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info
.for file in info install-info makeinfo texindex
	strip ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
