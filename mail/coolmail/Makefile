# $NetBSD: Makefile,v 1.11 2006/02/05 23:09:53 joerg Exp $

DISTNAME=		coolmail-1.3
PKGREVISION=		2
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
COMMENT=		Xbiff replacement with 3D animation and sound

OPSYSVARS+=		EXTRA_LIBS
EXTRA_LIBS.*=		-lcompat
EXTRA_LIBS.Interix=	-lSM
EXTRA_LIBS.IRIX=	# empty
MAKE_ENV+=		EXTRA_LIBS=${EXTRA_LIBS:Q}
MAKE_ENV+=		X11BASE=${PREFIX:Q}
USE_X11BASE=		yes

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	  ${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../mk/bsd.pkg.mk"
