# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:20 agc Exp $
#

DISTNAME=       texinfo-3.12
PKGNAME=	gtexinfo-3.12
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

MAINTAINER=	lamj@stat.cmu.edu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-catgets

post-install:
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info
.for file in info install-info makeinfo texindex
	strip ${PREFIX}/bin/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
