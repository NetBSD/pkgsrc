# $NetBSD: Makefile,v 1.1 2024/01/29 15:54:02 schmonz Exp $

DISTNAME=		dkimproxy-1.4.1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dkimproxy/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://dkimproxy.sourceforge.net/
COMMENT=		SMTP proxy that signs and/or verifies emails
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run

EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${PREFIX}/${EGDIR}/dkimproxy_in.conf.example \
			${PKG_SYSCONFDIR}/dkimproxy_in.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/dkimproxy_out.conf.example \
			${PKG_SYSCONFDIR}/dkimproxy_out.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/${EGDIR}

DEPENDS+=		p5-Mail-DKIM>=0.34:../../mail/p5-Mail-DKIM
DEPENDS+=		p5-Net-Server>=0.91:../../net/p5-Net-Server

.include "../../mk/bsd.pkg.mk"
