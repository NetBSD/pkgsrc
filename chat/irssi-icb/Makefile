# $NetBSD: Makefile,v 1.51 2024/06/06 10:48:48 jperkin Exp $

DISTNAME=	irssi-icb-0.17
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=mglocker/}
GITHUB_TAG=	c4e2ea8939b5b75d1941ebe3335475482d218838
DISTFILES=	${DISTNAME}-${GITHUB_TAG}.tar.gz

MAINTAINER=	jperkin@pkgsrc.org
HOMEPAGE=	http://www.irssi.org/
COMMENT=	Irssi plugin to access ICB networks
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoreconf autoconf automake gmake
GNU_CONFIGURE=	yes

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--with-irssi=${PREFIX}/include/irssi

INSTALLATION_DIRS+=	share/doc/irssi

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -i

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/irssi/README.icb

.include "../../chat/irssi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
