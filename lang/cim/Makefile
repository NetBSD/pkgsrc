# $NetBSD: Makefile,v 1.8 2001/04/14 21:43:46 jtb Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_PERL5=		YES

INFO_FILES=		cim.info

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

.include "../../mk/bsd.pkg.mk"
