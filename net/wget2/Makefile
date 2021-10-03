# $NetBSD: Makefile,v 1.1 2021/10/03 13:41:11 ryoon Exp $

DISTNAME=	wget2-2.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/wget/
COMMENT=	Retrieving files using HTTP, HTTPS, FTP and FTPS
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-doc # Needs pandoc

PKGCONFIG_OVERRIDE+=	libwget.pc.in

.include "options.mk"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/wget2_noinstall

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
