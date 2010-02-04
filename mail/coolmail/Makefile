# $NetBSD: Makefile,v 1.15 2010/02/04 01:48:01 joerg Exp $

DISTNAME=		coolmail-1.3
PKGREVISION=		2
CATEGORIES=		mail x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/mail/biffs/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Xbiff replacement with 3D animation and sound

PKG_DESTDIR_SUPPORT=	user-destdir

OPSYSVARS+=		EXTRA_LIBS
EXTRA_LIBS.*=		-lcompat
EXTRA_LIBS.Interix=	-lSM
EXTRA_LIBS.IRIX=	# empty
MAKE_ENV+=		EXTRA_LIBS=${EXTRA_LIBS:Q}
MAKE_ENV+=		X11BASE=${PREFIX:Q}
USE_X11BASE=		yes

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/Coolmail.ad \
	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/Coolmail

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
