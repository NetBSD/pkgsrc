# $NetBSD: Makefile,v 1.15 2023/11/24 12:56:30 ryoon Exp $

DISTNAME=	bc-1.07.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

USE_TOOLS+=		flex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		yes

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
