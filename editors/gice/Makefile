# $NetBSD: Makefile,v 1.62 2020/03/10 22:09:42 wiz Exp $
#

DISTNAME=		gice-0.6.2
PKGREVISION=		34
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice
INSTALLATION_DIRS=	bin

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
