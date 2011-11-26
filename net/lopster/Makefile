# $NetBSD: Makefile,v 1.24 2011/11/26 04:40:07 sbd Exp $
#

DISTNAME=	lopster-1.2.2
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
