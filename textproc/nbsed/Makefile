# $NetBSD: Makefile,v 1.29 2025/04/19 08:07:27 wiz Exp $

DISTNAME=		nbsed-20240312
PKGREVISION=		2
CATEGORIES=		textproc pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		NetBSD-current's sed(1)
LICENSE=		original-bsd AND modified-bsd

POLICY_UPDATE_LIMITED=	bootstrap

BOOTSTRAP_PKG=	yes

USE_FEATURES=		nbcompat
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name="s,sed,nbsed,"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
