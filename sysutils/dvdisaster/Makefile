# $NetBSD: Makefile,v 1.39 2018/11/12 03:52:53 ryoon Exp $

DISTNAME=	dvdisaster-0.79.5
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://dvdisaster.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shattered@NetBSD.org
HOMEPAGE=	http://www.dvdisaster.net/en/
COMMENT=	Protects data on optical media with error correcting codes
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*

BUILD_DEPENDS+=		gettext-tools>=0.14:../../devel/gettext-tools

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash gmake pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--buildroot=${DESTDIR}
CONFIGURE_ARGS+=	--with-embedded-src-path=no
CONFIG_SHELL=		${TOOLS_PATH.bash}
MAKE_FILE=		GNUmakefile

post-install:
	rm -f ${DESTDIR}${PREFIX}/bin/dvdisaster-uninstall.sh

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
