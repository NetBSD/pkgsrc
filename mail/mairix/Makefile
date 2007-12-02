# $NetBSD: Makefile,v 1.14 2007/12/02 12:56:08 tonio Exp $
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
