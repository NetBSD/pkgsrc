# $NetBSD: Makefile,v 1.1.1.1 1997/10/09 09:13:49 agc Exp $
# New ports collection makefile for:	GNU texinfo
# Version required:     3.9
# Date created:		7th October 1997
# Whom:			Alistair Crooks (agc@netbsd.org)
#

DISTNAME=       texinfo-3.9
PKGNAME=	gtexinfo-3.9
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}

GNU_CONFIGURE=	yes
MAN1=		info.1

post-install:
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/makeinfo.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info

.include <bsd.port.mk>
