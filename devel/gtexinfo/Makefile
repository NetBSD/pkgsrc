# $NetBSD: Makefile,v 1.43 2003/08/09 10:44:43 seb Exp $
#

DISTNAME=		texinfo-4.6
PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info file manipulation utilities

USE_BUILDLINK2=		yes
USE_GNU_GETTEXT=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}

INFO_FILES=		info-stnd.info info.info texinfo
TEST_TARGET=		check

post-patch:
	${MV} -f ${WRKSRC}/info/filesys.h ${WRKSRC}/info/filesys.h.orig
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@X11BASE@|${X11BASE}|g'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		< ${WRKSRC}/info/filesys.h.orig		\
		> ${WRKSRC}/info/filesys.h

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
