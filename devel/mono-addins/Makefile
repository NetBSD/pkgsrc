# $NetBSD: Makefile,v 1.33 2017/04/22 21:03:11 adam Exp $

DISTNAME=	mono-addins-1.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/mono-addins/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mono.Addins
COMMENT=	Framework for creating extensible applications
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no
ALL_ENV+=	PLATFORM=

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
