# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:39 joerg Exp $
#

DISTNAME=	aegis-4.15
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	Matthew@Aldous.com
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

GNU_CONFIGURE=	YES
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR:Q}
USE_TOOLS+=	groff gsoelim
BUILD_USES_MSGFMT=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
