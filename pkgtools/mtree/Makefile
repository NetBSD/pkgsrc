# $NetBSD: Makefile,v 1.10 2004/04/11 02:01:55 snj Exp $
#

DISTNAME=		mtree-20031220
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Utility for mapping and checking directory hierarchies

USE_BUILDLINK3=		# defined
GNU_CONFIGURE=		# defined

NO_PKGTOOLS_REQD_CHECK=	# defined
NO_CHECKSUM=		# defined
NO_MTREE=               # defined
NO_PKG_REGISTER=        # defined
NO_PACKAGE=             Deinstallation is not permitted
PKG_PRESERVE=           # defined

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

.include "../../pkgtools/libnbcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX:=		${PKG_TOOLS_BIN:C|/[^/]?bin$||}
.if ${PREFIX} == "/usr"
CONFIGURE_ARGS+=	--mandir=${PREFIX}/share/man
.else
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
.endif
