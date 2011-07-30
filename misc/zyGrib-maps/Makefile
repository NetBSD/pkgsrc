# $NetBSD: Makefile,v 1.5 2011/07/30 21:29:25 plunky Exp $
#

DISTNAME=	zyGrib-maps-2.4
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.zygrib.org/getfile.php?file=
DISTFILES=	zyGrib_maps2.4.tgz

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://www.zygrib.org/
COMMENT=	High resolution map files for zyGrib
LICENSE=	gnu-gpl-v3

DEPENDS+=	zyGrib>=2.0:../../misc/zyGrib

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	share/zyGrib/maps/gshhs

INSTALL_FILES=	maps/gshhs/gshhs_0.rim
INSTALL_FILES+=	maps/gshhs/gshhs_1.rim
INSTALL_FILES+=	maps/gshhs/rangs_0.cat
INSTALL_FILES+=	maps/gshhs/rangs_0.cel
INSTALL_FILES+=	maps/gshhs/rangs_1.cat
INSTALL_FILES+=	maps/gshhs/rangs_1.cel
INSTALL_FILES+=	maps/gshhs/wdb_borders_f.b
INSTALL_FILES+=	maps/gshhs/wdb_borders_h.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_f.b
INSTALL_FILES+=	maps/gshhs/wdb_rivers_h.b

WRKSRC=		${WRKDIR}/data

do-configure:

do-build:

do-install:
.for f in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/zyGrib/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
