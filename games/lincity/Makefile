# $NetBSD: Makefile,v 1.9 2001/08/29 22:41:12 jlam Exp $
#

DISTNAME=		lincity-1.11
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=games/strategy/} \
			ftp://ftp.demon.co.uk/pub/unix/linux/games/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.floot.demon.co.uk/lincity.html
COMMENT=		Free clone of SimCity for X11

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		# defined

ALL_TARGET=		xlincity
INSTALL_TARGET=		install-xlincity install-lib install-man

MAKE_ENV+=		EXTRA_OPTS="${CFLAGS}"

pre-build:
	${LN} -sf lincity.man ${WRKSRC}/xlincity.man

post-install:
	${LN} -sf lincity.6 ${PREFIX}/man/man6/xlincity.6

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
