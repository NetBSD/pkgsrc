# $NetBSD: Makefile,v 1.1.1.1 2004/05/16 00:53:02 xtraeme Exp $
#

DISTNAME=	flac123-0.0.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac-tools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://flac-tools.sourceforge.net/
COMMENT=	Command-line program for playing FLAC audio files

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
