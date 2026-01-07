# $NetBSD: Makefile,v 1.53 2026/01/07 08:47:48 wiz Exp $

DISTNAME=		mpop-1.4.21
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}releases/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://marlam.de/mpop/
COMMENT=		Small, fast and portable POP3 client
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS.Darwin+=	--with-macosx-keyring

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/mpop
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES=		${EGDIR}/mpoprc.example \
			${PKG_SYSCONFDIR}/mpoprc

.include "options.mk"

post-install: install-mpop-scripts
	${INSTALL_DATA} ${WRKSRC}/doc/mpoprc.example ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
