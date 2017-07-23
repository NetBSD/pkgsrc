# $NetBSD: Makefile,v 1.23 2017/07/23 16:09:57 adam Exp $

DISTNAME=	faad2-2.8.1
PKGNAME=	${DISTNAME:S/faad/xmms-faad/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	XMMS plugin for faad
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-xmms
CONFIGURE_ARGS+=	--with-mp4v2

SHLIBTOOL_OVERRIDE=	# empty
DISTINFO_FILE=		${.CURDIR}/../../audio/faad2/distinfo
PATCHDIR=		${.CURDIR}/../../audio/faad2/patches

BUILD_DIRS=		plugins/xmms/src
INSTALL_DIRS=		plugins/xmms

pre-configure:
	for dir in . ; do			\
		cd ${WRKSRC}/$$dir;		\
		aclocal -I .;			\
		autoheader;			\
		libtoolize --automake;		\
		automake --add-missing;		\
		autoconf;			\
	done

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
