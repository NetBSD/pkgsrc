# $NetBSD: Makefile,v 1.5 2001/02/16 05:44:04 jtb Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoreconf:../../devel/autoconf

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_PERL5=		YES

INFO_FILES=		cim.info

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

.include "../../mk/bsd.pkg.mk"
