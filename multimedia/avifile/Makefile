# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:01 tv Exp $

DISTNAME=	avifile-0.53.5
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/			\
		http://divx.euro.ru/					\
		http://www.toon.eu.org/divx/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://avifile.sourceforge.net/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS=	win32-codecs>=010122:../../multimedia/win32-codecs

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-win32-path="${LOCALBASE}/lib/win32"
CONFIGURE_ARGS+=	--disable-qt

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
