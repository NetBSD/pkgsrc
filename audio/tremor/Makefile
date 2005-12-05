# $NetBSD: Makefile,v 1.16 2005/12/05 20:49:50 rillig Exp $

DISTNAME=	tremor_snapshot_030406
PKGNAME=	tremor-1.0.2
PKGREVISION=	4
CATEGORIES=	devel audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Fixed point decoding library for the Ogg Vorbis audio encoding format

WRKSRC=         ${WRKDIR}/Tremor
AUTOCONF_REQD=		2.50
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake14 gmake
USE_LIBTOOL=		yes

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && automake --add-missing
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
