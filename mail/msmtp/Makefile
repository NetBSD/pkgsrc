# $NetBSD: Makefile,v 1.19 2008/01/18 05:08:27 tnn Exp $

DISTNAME=	msmtp-1.4.13
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	http://msmtp.sourceforge.net/
COMMENT=	SMTP plugin for MUAs

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/msmtp
CONF_FILES=	${EGDIR}/msmtprc-user.example \
		${PKG_SYSCONFDIR}/msmtprc

INFO_FILES=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Interix"
CPPFLAGS+=	-D__WINSOCK
.endif

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-user.example ${EGDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
