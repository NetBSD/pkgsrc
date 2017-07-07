# $NetBSD: Makefile,v 1.1 2017/07/07 04:03:06 adam Exp $

DISTNAME=	inetutils-1.9.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=inetutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/inetutils/
COMMENT=	GNU network utilities
LICENSE=	gnu-gpl-v3

INFO_FILES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-path-bshell=${SH:Q}
CONFIGURE_ARGS+=	--with-path-cp=${CP:Q}

TEST_TARGET=		check

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
