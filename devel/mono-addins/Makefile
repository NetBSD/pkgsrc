# $NetBSD: Makefile,v 1.3 2008/02/19 13:43:19 xtraeme Exp $

DISTNAME=	mono-addins-0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.com/sources/mono-addins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/Mono.Addins
COMMENT=	Framework for creating extensible applications

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
