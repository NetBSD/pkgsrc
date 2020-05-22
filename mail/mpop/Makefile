# $NetBSD: Makefile,v 1.32 2020/05/22 10:56:19 adam Exp $

DISTNAME=	mpop-1.2.6
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpop/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://mpop.sourceforge.net/
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
