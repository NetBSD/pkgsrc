# $NetBSD: Makefile,v 1.23 2006/02/05 23:10:55 joerg Exp $
#

DISTNAME=		medusa-0.5.1
PKGREVISION=		9
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/medusa/0.5/}	\
			http://download.eazel.com/source/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.eazel.com/
COMMENT=		File system indexing engine

BROKEN_IN=		pkgsrc-2005Q4

DEPENDS+=		psmisc-[0-9]*:../../sysutils/psmisc

GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
