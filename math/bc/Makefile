# $NetBSD: Makefile,v 1.17 2025/01/13 02:22:47 ktnb Exp $

DISTNAME=	bc-1.08.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		yes

.include "../../mk/readline.buildlink3.mk"
.if ${READLINE_TYPE} == "readline"
USE_TOOLS+=	flex:run
.endif
.include "../../mk/bsd.pkg.mk"
