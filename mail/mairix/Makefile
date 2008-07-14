# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:08 joerg Exp $
#

DISTNAME=		mairix-0.21
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mairix/}

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://www.rc0.org.uk/mairix/
COMMENT=		Program for indexing and searching email messages

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_TOOLS+=		bison flex

.include "../../mk/bsd.pkg.mk"
