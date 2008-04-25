# $NetBSD: Makefile,v 1.4 2008/04/25 08:14:57 kefren Exp $

DISTNAME=	monodoc-1.9
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/monodoc/
EXTRACT_SUFX=	.zip

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Documentation for the Mono class libraries

.include "../../lang/mono/Makefile.common"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
