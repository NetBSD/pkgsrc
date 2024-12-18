# $NetBSD: Makefile,v 1.16 2024/12/18 16:12:34 nros Exp $

DISTNAME=	bc-1.07.1
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
