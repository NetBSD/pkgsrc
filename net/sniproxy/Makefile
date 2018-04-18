# $NetBSD: Makefile,v 1.6 2018/04/18 19:34:11 kamil Exp $

DISTNAME=	sniproxy-0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dlundquist/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/dlundquist/sniproxy/
COMMENT=	Proxy that routes based on TLS server name extension
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_TOOLS+=	autoconf aclocal automake pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/sniproxy.conf ${PKG_SYSCONFDIR}/sniproxy.conf

CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -D_XOPEN_SOURCE=600
LDFLAGS.SunOS+=		-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf --install && automake --add-missing --copy

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sniproxy.conf ${DESTDIR}${EGDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
