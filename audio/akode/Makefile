# $NetBSD: Makefile,v 1.7 2012/09/11 23:59:21 asau Exp $
#

PKGNAME=		akode-2.0.2
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple audio decoding framework (base package)
LICENSE=		gnu-lgpl-v2

.include "../../audio/akode/Makefile.common"

REPLACE_SH=		akode/akode-config.in

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
