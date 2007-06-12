# $NetBSD: Makefile,v 1.13 2007/06/12 15:23:48 tonio Exp $
#

DISTNAME=		mairix-0.20
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mairix/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

USE_TOOLS+=		bison flex

.include "../../mk/bsd.pkg.mk"
