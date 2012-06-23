# $NetBSD: Makefile,v 1.16 2012/06/23 21:45:24 dholland Exp $

DISTNAME=		coolmail-1.3
PKGREVISION=		3
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Xbiff replacement with 3D animation and sound

PKG_DESTDIR_SUPPORT=	user-destdir

OPSYSVARS+=		EXTRA_LIBS
EXTRA_LIBS.Interix=	-lSM
MAKE_ENV+=		EXTRA_LIBS=${EXTRA_LIBS:Q}

MAKE_ENV+=		X11BASE=${PREFIX:Q}
INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
