# $NetBSD: Makefile,v 1.82 2026/09/02 19:00:48 wiz Exp $

DISTNAME=	mp3info-0.8.5a
PKGNAME=	g${DISTNAME}
PKGREVISION=	49
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/linux/apps/sound/mp3-utils/mp3info/
MASTER_SITES+=	${MASTER_SITE_SUNSITE:=apps/sound/mp3-utils/mp3info/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ibiblio.org/mp3info/
COMMENT=	Utility to read and modify the ID3 tags of MP3 files
LICENSE=	gnu-gpl-v2

CONFLICTS=	mp3info-[0-9]*

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
