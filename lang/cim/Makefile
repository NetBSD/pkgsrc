# $NetBSD: Makefile,v 1.9 2001/04/21 01:10:58 jtb Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_PERL5=		yes

INFO_FILES=		cim.info

.include "../../mk/bsd.pkg.mk"
