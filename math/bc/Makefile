# $NetBSD: Makefile,v 1.18 2025/07/02 02:59:05 markd Exp $

DISTNAME=	bc-1.08.2
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
