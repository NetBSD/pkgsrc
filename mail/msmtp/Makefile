# $NetBSD: Makefile,v 1.70 2018/09/19 09:26:45 leot Exp $

DISTNAME=	msmtp-1.8.0
CATEGORIES=	mail
MASTER_SITES=	https://marlam.de/msmtp/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	https://marlam.de/msmtp/
COMMENT=	SMTP plugin for MUAs
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt xgettext

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS.Darwin+=	--with-macosx-keyring

EGDIR=		${PREFIX}/share/examples/msmtp
CONF_FILES=	${EGDIR}/msmtprc-user.example \
		${PKG_SYSCONFDIR}/msmtprc

INFO_FILES=	yes
PLIST_VARS+=	scripts

CPPFLAGS.Interix+=	-D__WINSOCK

.include "options.mk"

.PHONY: install-msmtp-scripts
post-install: install-msmtp-scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-user.example ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
