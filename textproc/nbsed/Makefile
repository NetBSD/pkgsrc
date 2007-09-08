# $NetBSD: Makefile,v 1.17 2007/09/08 21:58:01 jlam Exp $

DISTNAME=		nbsed-20040821
PKGREVISION=		1
CATEGORIES=		textproc pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		NetBSD-current's sed(1)

NO_CHECKSUM=		yes
NO_MTREE=		yes
USE_FEATURES=		nbcompat
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name="s,sed,nbsed,"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
