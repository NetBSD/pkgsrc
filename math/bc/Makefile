# $NetBSD: Makefile,v 1.13 2015/12/12 19:50:36 markd Exp $

DISTNAME=	bc-1.06.95
CATEGORIES=	math
MASTER_SITES=	ftp://alpha.gnu.org/gnu/bc/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.gnu.org/software/bc/bc.html
COMMENT=	Arbitrary precision calculator language

USE_TOOLS+=		flex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-readline
INFO_FILES=		yes

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
