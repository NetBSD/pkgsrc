# $NetBSD: Makefile,v 1.1.1.1 2002/09/24 09:33:00 chris Exp $

DISTNAME=	tremor_snapshot_020923
PKGNAME=	tremor-1.2.0
WRKSRC=         ${WRKDIR}/Tremor
CATEGORIES=	devel audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Fixed point decoding library for the Ogg Vorbis audio encoding format

BUILD_DEPENDS=		autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/bsd.pkg.mk"
