# $NetBSD: Makefile,v 1.102 2025/04/19 07:58:02 wiz Exp $

DISTNAME=		msmtp-1.8.28
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}releases/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		bcv@hub3.net
HOMEPAGE=		https://marlam.de/msmtp/
COMMENT=		SMTP client for MUAs
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt xgettext
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS.Darwin+=	--with-macosx-keyring

CPPFLAGS.Interix+=	-D__WINSOCK
LDFLAGS.SunOS+=		-lsocket -lnsl

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/msmtp
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES=		${EGDIR}/msmtprc-user.example \
			${PKG_SYSCONFDIR}/msmtprc

.include "options.mk"

post-install: install-msmtp-scripts
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-user.example ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
