# $NetBSD: Makefile,v 1.13 2002/08/28 02:14:36 jlam Exp $

DISTNAME=	avifile-0.53.5
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/			\
		http://divx.euro.ru/					\
		http://www.toon.eu.org/divx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://divx.euro.ru/
COMMENT=	MPEG-4 (DivX) video player library

DEPENDS=	win32-codecs>=010122:../../graphics/win32-codecs

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-win32-path="${LOCALBASE}/lib/win32"
CONFIGURE_ARGS+=	--without-qt

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
