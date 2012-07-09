# $NetBSD: Makefile,v 1.38 2012/07/09 10:09:48 ryoon Exp $

DISTNAME=	msmtp-1.4.28
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	http://msmtp.sourceforge.net/
COMMENT=	SMTP plugin for MUAs
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt xgettext

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/msmtp
CONF_FILES=	${EGDIR}/msmtprc-user.example \
		${PKG_SYSCONFDIR}/msmtprc

INFO_FILES=	yes
PLIST_VARS+=	scripts

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Interix"
CPPFLAGS+=	-D__WINSOCK
.endif

.include "options.mk"

.PHONY: install-msmtp-scripts
post-install: install-msmtp-scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-user.example ${DESTDIR}${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
