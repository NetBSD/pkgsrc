# $NetBSD: Makefile,v 1.9 2004/08/27 03:45:08 jlam Exp $

DISTNAME=		nbsed-20040821
CATEGORIES=		textproc pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		NetBSD-current's sed(1)

USE_BUILDLINK3=		yes
NO_CHECKSUM=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name="s,sed,nbsed,"

.include "../../mk/bsd.prefs.mk"

.if defined(LIBNBCOMPAT_STYLE) && (${LIBNBCOMPAT_STYLE} == "inplace")  
.  include "../../pkgtools/libnbcompat/inplace.mk"
.else
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
