# $NetBSD: Makefile,v 1.22 2012/03/08 01:12:07 joerg Exp $

DISTNAME=		nbsed-20120308
CATEGORIES=		textproc pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		NetBSD-current's sed(1)

PKG_DESTDIR_SUPPORT=	user-destdir
BOOTSTRAP_PKG=	yes

USE_FEATURES=		nbcompat
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name="s,sed,nbsed,"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
