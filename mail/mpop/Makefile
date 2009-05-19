# $NetBSD: Makefile,v 1.12 2009/05/19 08:59:22 wiz Exp $
#

DISTNAME=	mpop-1.0.12
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpop/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://mpop.sourceforge.net/
COMMENT=	Small, fast and portable POP3 client
LICENSE=	gnu-gpl-v3

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
