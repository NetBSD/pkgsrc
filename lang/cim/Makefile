# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 21:59:30 jtb Exp $

DISTNAME=	cim-3.30
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=cim/}

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/cim/cim.html

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=${WKRSRC}/libtool
LTCONFIG_OVERRIDE=${WKRSRC}/ltconfig
USE_PERL5=	yes

INFO_FILES=		cim.info

.include "../../mk/bsd.pkg.mk"
