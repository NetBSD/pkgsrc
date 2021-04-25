# $NetBSD: Makefile,v 1.18 2021/04/25 07:21:17 nia Exp $
#

DISTNAME=	libfm-1.3.0.2
PKGNAME=	libfm-extra-1.3.0.2
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcmanfm/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcmanfm.sourceforge.net/
COMMENT=	File management library (extra)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool pkg-config msgfmt

CONFIGURE_ARGS+=	--with-extra-only
INSTALLATION_DIRS=	include/libfm

# XXX: walk-around bug in build wrappers
#      they try to copy $PREFIX/include/libfm to work dir and there link libfm -> libfm-1.0 is resolved
#      in the end a consumer of libfm cannot find nonexisting include/libfm
post-install:
	${RUN} ${RM} -f ${DESTDIR}${PREFIX}/include/libfm
	${RUN} ${CP} -r ${DESTDIR}${PREFIX}/include/libfm-1.0 ${DESTDIR}${PREFIX}/include/libfm

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
