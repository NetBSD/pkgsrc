# $NetBSD: Makefile,v 1.30 2014/05/05 00:48:20 ryoon Exp $
#

DISTNAME=		dvdisaster-0.72.4
PKGREVISION=		11
CATEGORIES=		sysutils
MASTER_SITES=		http://dvdisaster.net/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://www.dvdisaster.net/en/
COMMENT=		Protects data on optical media with error correcting codes
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*

BUILD_DEPENDS+=		gettext-tools>=0.14:../../devel/gettext-tools

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

ONLY_FOR_COMPILER=	gcc
USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash gmake pkg-config

MAKE_JOBS_SAFE=		no

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--buildroot=${DESTDIR}
CONFIGURE_ARGS+=	--with-embedded-src-path=no
CONFIG_SHELL=		${TOOLS_PATH.bash}
MAKE_FILE=		GNUmakefile

CHECK_PORTABILITY_SKIP+=macinst/launcher.sh

post-install:
	rm -f ${DESTDIR}${PREFIX}/bin/dvdisaster-uninstall.sh

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
