# $NetBSD: Makefile,v 1.2 2008/02/19 09:59:33 xtraeme Exp $

DISTNAME=	monodoc-${MONO_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/monodoc/
EXTRACT_SUFX=	.zip

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Documentation for the Mono class libraries

.include "../../lang/mono/Makefile.version"

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
