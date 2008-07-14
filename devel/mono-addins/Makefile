# $NetBSD: Makefile,v 1.7 2008/07/14 12:56:03 joerg Exp $

DISTNAME=	mono-addins-0.3.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/mono-addins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mono.Addins
COMMENT=	Framework for creating extensible applications

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
