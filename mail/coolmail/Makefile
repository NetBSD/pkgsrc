# $NetBSD: Makefile,v 1.5 2003/07/21 16:56:43 martti Exp $

DISTNAME=		coolmail-1.3
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
COMMENT=		Xbiff replacement with 3D animation and sound

MAKE_ENV+=		X11BASE=${PREFIX}
USE_X11BASE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	  ${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../mk/bsd.pkg.mk"
