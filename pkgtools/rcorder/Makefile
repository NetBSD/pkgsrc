# $NetBSD: Makefile,v 1.6 2005/01/06 05:32:30 tv Exp $
#

DISTNAME=		rcorder-20031013
CATEGORIES=		pkgtools sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Print a dependency ordering of interdependent files

USE_BUILDLINK3=		yes
NO_CHECKSUM=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if defined(LIBNBCOMPAT_STYLE) && (${LIBNBCOMPAT_STYLE} == "inplace")  
.  include "../../pkgtools/libnbcompat/inplace.mk"
.else
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
