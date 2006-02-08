# $NetBSD: Makefile,v 1.9 2006/02/08 16:48:59 joerg Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGREVISION=		3
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
BUILD_USES_MSGFMT=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
