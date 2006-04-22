# $NetBSD: Makefile,v 1.20 2006/04/22 16:44:25 joerg Exp $
#

DISTNAME=	lopster-1.2.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lopster.sourceforge.net/
COMMENT=	Yet another Gtk+ Napster clone

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

post-extract:
	${RM} -fr ${WRKSRC}/intl

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
