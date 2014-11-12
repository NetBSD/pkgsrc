# $NetBSD: Makefile,v 1.1 2014/11/12 18:38:18 khorben Exp $

DISTNAME=	flvstreamer-2.1c1
WRKSRC=		${WRKDIR}/flvstreamer
CATEGORIES=	multimedia
MASTER_SITES=	http://download.savannah.gnu.org/releases/flvstreamer/source/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://savannah.nongnu.org/projects/flvstreamer
COMMENT=	Open source command-line RTMP client

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	posix
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
