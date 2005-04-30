# $NetBSD: Makefile,v 1.17 2005/04/30 08:54:59 agc Exp $
#

DISTNAME=	libutf-2.10
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	UTF-8 character set support library, including regular expressions

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
BUILD_TARGET=	tst

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/libutf
CONF_FILES=	${EGDIR}/langcoll.utf ${PKG_SYSCONFDIR}/langcoll.utf

.include "../../mk/bsd.pkg.mk"
