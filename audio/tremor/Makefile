# $NetBSD: Makefile,v 1.10 2004/02/14 17:21:34 jlam Exp $

DISTNAME=	tremor_snapshot_030406
PKGNAME=	tremor-1.0.2
PKGREVISION=	3
CATEGORIES=	devel audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Fixed point decoding library for the Ogg Vorbis audio encoding format

WRKSRC=         ${WRKDIR}/Tremor
AUTOMAKE_REQD=		1.4
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

PLIST_SUBST+=		DISTNAME=${DISTNAME}

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
