# $NetBSD: Makefile,v 1.16 2012/10/08 12:19:16 asau Exp $
#

DISTNAME=		mairix-0.21
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mairix/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_TOOLS+=		bison flex

.include "../../mk/bsd.pkg.mk"
