# $NetBSD: Makefile,v 1.8 2002/08/26 06:59:47 jlam Exp $
#

DISTNAME=	aalib-1.4rc4
PKGNAME=	aalib-1.4.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library

CONFLICTS+=	aalib-x11<=1.4.0.4

WRKSRC=		${WRKDIR}/aalib-1.4.0
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--with-x11-driver=no

.if (${MACHINE_ARCH} == arm32)
 GCC_VERSION!=           gcc --version

. if (${GCC_VERSION:C/-.*$$//} == egcs)
. include "../../lang/gcc/Makefile.gcc"
. endif

.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
