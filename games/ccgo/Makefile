# $NetBSD: Makefile,v 1.8 2003/12/13 00:45:23 wiz Exp $
#

DISTNAME=		ccgo-0.3.1
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://ccdw.org/~cjj/prog/ccgo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ccdw.org/~cjj/prog/ccgo/
COMMENT=		Go board with IGS and gnugo interface

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

post-patch:
.for src in game_setup.cc settings.cc
	${CP} ${WRKSRC}/${src} ${WRKSRC}/${src}.old
	${SED} -e 's|/usr/games|${PREFIX}/bin|g' < ${WRKSRC}/${src}.old > ${WRKSRC}/${src}
.endfor

.include "../../textproc/regexx/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gconfmm/buildlink2.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
