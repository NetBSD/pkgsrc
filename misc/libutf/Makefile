# $NetBSD: Makefile,v 1.10 2002/12/23 08:03:02 jmmv Exp $
#

DISTNAME=	libutf-2.10
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	UTF-8 character set support library, including regular expressions

GNU_CONFIGURE=	# defined
USE_LIBTOOL=	# defined
ALL_TARGET=	tst

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/libutf
CONF_FILES=	${EGDIR}/langcoll.utf ${PKG_SYSCONFDIR}/langcoll.utf

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
