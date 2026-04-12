# $NetBSD: Makefile,v 1.19 2026/04/12 17:15:20 tnn Exp $

DISTNAME=	bc-1.08.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=bc/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		yes

.include "../../mk/readline.buildlink3.mk"
.if ${READLINE_TYPE} == "readline"
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--without-libedit
USE_TOOLS+=		flex:run
.elif ${READLINE_TYPE} == "editline"
CONFIGURE_ARGS+=	--with-libedit
CONFIGURE_ARGS+=	--without-readline
.endif
.include "../../mk/bsd.pkg.mk"
