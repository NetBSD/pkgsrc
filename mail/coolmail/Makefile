# $NetBSD: Makefile,v 1.4 2001/02/17 18:24:41 wiz Exp $

DISTNAME=		coolmail-1.3
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
COMMENT=		xbiff replacement with 3D animation and sound

MAKE_ENV+=		X11BASE=${PREFIX}
USE_X11BASE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	  ${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../mk/bsd.pkg.mk"
