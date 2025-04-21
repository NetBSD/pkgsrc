# $NetBSD: Makefile,v 1.18 2025/04/21 20:56:54 wiz Exp $

DISTNAME=		coolmail-1.3
PKGREVISION=		3
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Xbiff replacement with 3D animation and sound

OPSYSVARS+=		EXTRA_LIBS
MAKE_ENV+=		EXTRA_LIBS=${EXTRA_LIBS:Q}

MAKE_ENV+=		X11BASE=${PREFIX:Q}
INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
