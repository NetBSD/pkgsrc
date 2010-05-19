# $NetBSD: Makefile,v 1.11 2010/05/19 18:28:15 drochner Exp $

DISTNAME=	flac123-0.0.11
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac-tools/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://flac-tools.sourceforge.net/
COMMENT=	Command-line program for playing FLAC audio files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
