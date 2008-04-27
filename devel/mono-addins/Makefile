# $NetBSD: Makefile,v 1.6 2008/04/27 09:21:27 wiz Exp $

DISTNAME=	mono-addins-0.3.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/mono-addins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mono.Addins
COMMENT=	Framework for creating extensible applications

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
