# $NetBSD: Makefile,v 1.79 2014/05/05 00:47:38 ryoon Exp $
#

DISTNAME=		snd-9.9
PKGREVISION=		23
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=snd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ccrma.stanford.edu/software/snd/
COMMENT=		X based sound editor

DEPENDS+=		flac-[0-9]*:../../audio/flac
DEPENDS+=		speex-[0-9]*:../../audio/speex
DEPENDS+=		vorbis-tools-[0-9]*:../../audio/vorbis-tools

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config

BUILD_TARGET=		snd
MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}/snd-9

INSTALLATION_DIRS=	${PKGLOCALEDIR}/locale/de/LC_MESSAGES
INSTALL_MAKE_FLAGS+=	localedir=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale

post-install:
	${INSTALL_DATA} ${WRKSRC}/po/de.gmo \
	    ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/de/LC_MESSAGES/snd.mo

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
