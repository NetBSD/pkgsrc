# $NetBSD: Makefile,v 1.17 2016/04/01 16:44:32 jperkin Exp $
#

DISTNAME=		mairix-0.21
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mairix/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

USE_TOOLS+=		bison flex

.include "../../mk/bsd.pkg.mk"
