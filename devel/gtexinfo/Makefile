# $NetBSD: Makefile,v 1.27 2002/04/04 11:10:21 seb Exp $
#

DISTNAME=		texinfo-4.0
PKGNAME=		gtexinfo-4.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info file manipulation utilities

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-catgets
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../devel/zlib/buildlink.mk"

INSTALL_INFO=	${PREFIX}/bin/install-info

post-patch:
	${MV} -f ${WRKSRC}/info/filesys.h ${WRKSRC}/info/filesys.h.orig
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@X11BASE@|${X11BASE}|g'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		< ${WRKSRC}/info/filesys.h.orig		\
		> ${WRKSRC}/info/filesys.h

post-install:
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${INSTALL_INFO} --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info

.include "../../mk/bsd.pkg.mk"
