# $NetBSD: Makefile,v 1.37 2020/11/20 13:50:23 nia Exp $

DISTNAME=		xgalaga-2.1.1.0
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xgalaga/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/xgalaga/
COMMENT=		Very fast true-to-the-original port of galaga for X11
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/xgalaga
INSTALLATION_DIRS+=	${PKGMANDIR}/man6

post-install:
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xgalaga/README

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
