# $NetBSD: Makefile,v 1.4 2006/06/09 16:14:37 minskim Exp $
#

DISTNAME=		hobbitclient-0.3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=hobbitmon/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://hobbitmon.sourceforge.net/
COMMENT=		Client for Hobbit Monitor or Big brother

GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc
BUILD_TARGET=		hobbitc

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
