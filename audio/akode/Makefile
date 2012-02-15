# $NetBSD: Makefile,v 1.6 2012/02/15 19:31:19 hans Exp $
#

PKGNAME=		akode-2.0.2
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple audio decoding framework (base package)
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_SH=		akode/akode-config.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
