# $NetBSD: Makefile,v 1.11 2003/01/28 22:03:44 jlam Exp $
#

DISTNAME=	libutf-2.10
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	UTF-8 character set support library, including regular expressions

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
ALL_TARGET=	tst

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/libutf
CONF_FILES=	${EGDIR}/langcoll.utf ${PKG_SYSCONFDIR}/langcoll.utf

.include "../../mk/bsd.pkg.mk"
