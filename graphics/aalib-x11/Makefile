# $NetBSD: Makefile,v 1.2 2002/03/25 14:45:25 cjep Exp $
#

DISTNAME=	aalib-1.4rc4
PKGNAME=	aalib-x11-1.4.0.4
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://aa-project.sourceforge.net/aalib/
COMMENT=	ASCII Art library with X11 support

CONFLICTS+=	aalib-[0-9]*

WRKSRC=		${WRKDIR}/aalib-1.4.0
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_BUILDLINK_ONLY=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.if (${MACHINE_ARCH} == arm32)
 GCC_VERSION!=           gcc --version

. if (${GCC_VERSION:C/-.*$$//} == egcs)
. include "../../lang/gcc/Makefile.gcc"
. endif

.endif

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
