# $NetBSD: Makefile,v 1.6 2008/07/14 12:56:07 joerg Exp $

DISTNAME=	monodoc-1.9
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/monodoc/
EXTRACT_SUFX=	.zip

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Documentation for the Mono class libraries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
