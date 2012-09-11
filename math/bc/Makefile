# $NetBSD: Makefile,v 1.10 2012/09/11 23:04:17 asau Exp $

DISTNAME=	bc-1.06
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

USE_TOOLS+=		flex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		# PLIST

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
