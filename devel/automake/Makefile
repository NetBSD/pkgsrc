# $NetBSD: Makefile,v 1.2 1997/10/06 14:30:54 agc Exp $
# New ports collection makefile for:	automake
# Version required:	1.2
# Date created:		15 March 1997
# Whom:			FUJIMOTO Kensaku <fujimoto@oscar.elec.waseda.ac.jp>
#
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PREFIX}/bin/perl
STRIP=		 # none

OPSYS!= uname -s

.if (${OPSYS} != "NetBSD")
# agc - this assumes /usr/share/info/dir and install-info
pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
.endif

.include <bsd.port.mk>
