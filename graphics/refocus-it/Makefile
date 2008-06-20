# $NetBSD: Makefile,v 1.13 2008/06/20 01:09:22 joerg Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
#just build the command line tool
CONFIGURE_ARGS+=	--without-gimp
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
