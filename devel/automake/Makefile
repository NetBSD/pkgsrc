# New ports collection makefile for:	automake
# Version required:	1.3
# Date created:		14 April 1998
# Whom:			Hubert Feyrer <hubert.feyrer@rz.uni-regensburg.de>
#
# $NetBSD: Makefile,v 1.10 1998/04/14 01:51:06 hubertf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl
STRIPFLAG=	# none

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
