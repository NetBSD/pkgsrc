# $NetBSD: Makefile,v 1.9 2007/03/16 19:05:17 reed Exp $
#

DISTNAME=	mpop-1.0.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpop/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://mpop.sourceforge.net/
COMMENT=	Small, fast and portable POP3 client

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--enable-nls

EGDIR=		${PREFIX}/share/examples/mpop

.include "options.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
