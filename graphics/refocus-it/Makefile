# $NetBSD: Makefile,v 1.11 2006/04/13 18:23:34 jlam Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

GNU_CONFIGURE=		yes
#just build the command line tool
CONFIGURE_ARGS+=	--without-gimp
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
