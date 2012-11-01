# $NetBSD: Makefile,v 1.1 2012/11/01 04:06:21 asau Exp $

DISTNAME=	plinkseq-0.08
CATEGORIES=	biology
MASTER_SITES=	http://atgu.mgh.harvard.edu/plinkseq/dist/version-0.08/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://atgu.mgh.harvard.edu/plinkseq/
COMMENT=	C/C++ library for working with human genetic variation data
LICENSE=	gnu-gpl-v2	# Assuming same as plink.  No info on web.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	bash:run
REPLACE_BASH=	browser/pbrowse.in index/index.in

.include "../../mk/bsd.prefs.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

.include "../../devel/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
