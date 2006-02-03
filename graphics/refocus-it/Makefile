# $NetBSD: Makefile,v 1.7 2006/02/03 13:55:58 rillig Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

GNU_CONFIGURE=		yes
#just build the command line tool
CONFIGURE_ARGS+=	--without-gimp
USE_PKGLOCALEDIR=	yes
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
