# $NetBSD: Makefile,v 1.4 2001/02/15 22:10:18 skrll Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_PERL5=		YES

INFO_FILES=		cim.info

.include "../../mk/bsd.pkg.mk"
