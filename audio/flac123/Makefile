# $NetBSD: Makefile,v 1.14 2014/10/10 21:20:28 snj Exp $

DISTNAME=	flac123-0.0.12-release
PKGNAME=	${DISTNAME:S/-release//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flac-tools/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://flac-tools.sourceforge.net/
COMMENT=	Command-line program for playing FLAC audio files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
