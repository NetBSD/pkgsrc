# $NetBSD: Makefile,v 1.2 2000/12/13 22:33:25 jtb Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WKRSRC}/libtool
LTCONFIG_OVERRIDE=	${WKRSRC}/ltconfig
USE_PERL5=		YES

INFO_FILES=		cim.info

.include "../../mk/bsd.pkg.mk"
