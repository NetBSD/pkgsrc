# $NetBSD: Makefile,v 1.27 2018/03/26 19:43:30 dholland Exp $

DISTNAME=	tremor-562307a
PKGNAME=	tremor-1.0.2.20180316
CATEGORIES=	devel audio
# No releases.
#GIT_COMMIT=	562307a4a7082e24553f3d2c55dab397a17c4b4f
#MASTER_SITES=	"http://git.xiph.org/?p=tremor.git;a=snapshot;sf=tgz;h=${GIT_COMMIT};"
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xiph.org/vorbis/
COMMENT=	Fixed point decoding library for the Ogg Vorbis audio encoding format
LICENSE=	modified-bsd

AUTOCONF_REQD=		2.50
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

pre-configure:
	touch ${WRKSRC}/config.h.in
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && automake --add-missing
	cd ${WRKSRC} && autoconf

.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
