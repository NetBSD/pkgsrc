# $NetBSD: Makefile,v 1.82 2024/05/16 06:15:30 wiz Exp $

DISTNAME=	libfprint-0.7.0
PKGREVISION=	42
CATEGORIES=	security devel
MASTER_SITES=	https://people.freedesktop.org/~anarsoul/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/fprint/
COMMENT=	Fingerprint reader access library
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake
USE_LANGUAGES=		c

#CONFIGURE_ARGS+=	--enable-debug-log
CONFIGURE_ARGS+=	--enable-examples-build

INSTALLATION_DIRS+=	lib bin

post-install:
	for pp in enroll img_capture verify verify_live; do \
		${INSTALL_SCRIPT} ${WRKSRC}/examples/$${pp} \
			${DESTDIR}${PREFIX}/bin/ ; \
	done

.include "../../x11/pixman/buildlink3.mk"
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
