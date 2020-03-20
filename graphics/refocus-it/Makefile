# $NetBSD: Makefile,v 1.18 2020/03/20 11:57:52 nia Exp $
#

DISTNAME=		refocus-it-2.0.0
PKGREVISION=		4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

GNU_CONFIGURE=			yes
#just build the command line tool
CONFIGURE_ARGS+=		--without-gimp
USE_PKGLOCALEDIR=		yes
USE_TOOLS+=			intltool msgfmt
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
