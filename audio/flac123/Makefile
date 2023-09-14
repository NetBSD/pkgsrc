# $NetBSD: Makefile,v 1.18 2023/09/14 04:04:52 snj Exp $

DISTNAME=	flac123-2.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=flac123/}
GITHUB_TAG=	v2.1.1

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://github.com/flac123/flac123
COMMENT=	Command-line program for playing FLAC audio files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
