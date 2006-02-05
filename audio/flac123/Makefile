# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:08 joerg Exp $
#

DISTNAME=	flac123-0.0.7
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac-tools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flac-tools.sourceforge.net/
COMMENT=	Command-line program for playing FLAC audio files

GNU_CONFIGURE=		yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
