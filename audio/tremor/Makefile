# $NetBSD: Makefile,v 1.4 2002/10/16 20:04:53 chris Exp $

DISTNAME=	tremor_snapshot_021016
PKGNAME=	tremor-1.0.2
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/Tremor
CATEGORIES=	devel audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	chris@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Fixed point decoding library for the Ogg Vorbis audio encoding format

AUTOMAKE_REQD=		1.4
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=		DISTNAME=${DISTNAME}

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
