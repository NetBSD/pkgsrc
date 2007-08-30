# $NetBSD: Makefile,v 1.21 2007/08/30 23:05:14 agc Exp $
#

DISTNAME=	libutf-3.0
CATEGORIES=	misc
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	UTF-8 character set support library, including regular expressions

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
BUILD_TARGET=	tst
PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/libutf
CONF_FILES=	${EGDIR}/langcoll.utf ${PKG_SYSCONFDIR}/langcoll.utf

.include "../../mk/bsd.pkg.mk"
