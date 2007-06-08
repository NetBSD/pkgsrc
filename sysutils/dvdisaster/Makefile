# $NetBSD: Makefile,v 1.1.1.1 2007/06/08 20:19:13 heinz Exp $
#

DISTNAME=		dvdisaster-0.70.4
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dvdisaster/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.dvdisaster.com/
COMMENT=		Protects data on optical media with error correcting codes

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		gettext-tools>=0.14:../../devel/gettext-tools

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash gmake pkg-config

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--docdir=${PREFIX:Q}/share/doc
CONFIGURE_ARGS+=	--localedir=${PREFIX:Q}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR}
CONFIGURE_ARGS+=	--buildroot=${DESTDIR:Q}
CONFIGURE_ARGS+=	--with-embedded-src-path=no
CONFIG_SHELL=		${TOOLS_PATH.bash}
MAKE_FILE=		GNUmakefile

pre-configure:
	cp ${FILESDIR:Q}/scsi-netbsd.c ${WRKSRC:Q}

post-install:
	rm -f ${DESTDIR:Q}${PREFIX:Q}/bin/dvdisaster-uninstall.sh

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
