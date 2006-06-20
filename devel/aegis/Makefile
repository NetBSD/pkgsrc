# $NetBSD: Makefile,v 1.9 2006/06/20 22:07:38 minskim Exp $
#

DISTNAME=	aegis-4.15
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	Matthew@Aldous.com
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR:Q}
USE_TOOLS+=		groff gsoelim msgfmt yacc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
