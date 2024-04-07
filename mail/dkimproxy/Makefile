# $NetBSD: Makefile,v 1.2 2024/04/07 18:22:08 ryoon Exp $

DISTNAME=		dkimproxy-1.4.1
PKGREVISION=		1
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

DKIMPROXY_USER?=	dkimproxy
DKIMPROXY_GROUP?=	dkimproxy
PKG_USERS_VARS+=	DKIMPROXY_USER
PKG_GROUPS_VARS+=	DKIMPROXY_GROUP
PKG_GROUPS=		${DKIMPROXY_GROUP}
PKG_USERS=		${DKIMPROXY_USER}:${DKIMPROXY_GROUP}

FILES_SUBST+=		DKIMPROXY_USER=${DKIMPROXY_USER}
FILES_SUBST+=		DKIMPROXY_GROUP=${DKIMPROXY_GROUP}

RCD_SCRIPTS+=		dkimproxy_in
RCD_SCRIPTS+=		dkimproxy_out

EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${PREFIX}/${EGDIR}/dkimproxy_in.conf.example \
			${PKG_SYSCONFDIR}/dkimproxy_in.conf
CONF_FILES+=		${PREFIX}/${EGDIR}/dkimproxy_out.conf.example \
			${PKG_SYSCONFDIR}/dkimproxy_out.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/${EGDIR}

DEPENDS+=		p5-Mail-DKIM>=0.34:../../mail/p5-Mail-DKIM
DEPENDS+=		p5-Net-Server>=0.91:../../net/p5-Net-Server

.include "../../mk/bsd.pkg.mk"
