# $NetBSD: Makefile,v 1.39 2023/01/22 00:23:18 leot Exp $

DISTNAME=	mpop-1.4.17
CATEGORIES=	mail
MASTER_SITES=	https://marlam.de/mpop/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://marlam.de/mpop
COMMENT=	Small, fast and portable POP3 client
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-nls

EGDIR=		${PREFIX}/share/examples/mpop
INSTALLATION_DIRS+=	${EGDIR}

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
