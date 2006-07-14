# $NetBSD: Makefile,v 1.25 2006/07/14 18:48:43 jlam Exp $
#

DISTNAME=		pax-20060202
CATEGORIES=		archivers pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		POSIX standard archiver with many extensions

GNU_CONFIGURE=		yes

NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
PKG_PRESERVE=		yes

.include "../../mk/bsd.prefs.mk"

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.if defined(LIBNBCOMPAT_STYLE) && (${LIBNBCOMPAT_STYLE} == "inplace")
.  include "../../pkgtools/libnbcompat/inplace.mk"
.else
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
