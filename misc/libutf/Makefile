# $NetBSD: Makefile,v 1.22 2009/05/22 18:17:57 zafer Exp $
#

DISTNAME=	libutf-3.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP}

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
