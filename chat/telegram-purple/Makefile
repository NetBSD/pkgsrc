# $NetBSD: Makefile,v 1.11 2020/11/05 09:07:37 ryoon Exp $

DISTNAME=	telegram-purple_1.3.1.orig
PKGNAME=	telegram-purple-1.3.1
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=majn/}
GITHUB_PROJECT=	telegram-purple
GITHUB_RELEASE=	v1.3.1

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/majn/telegram-purple/
COMMENT=	libpurple protocol plugin for the Telegram messenger
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_TOOLS+=	gmake msgfmt pkg-config

GNU_CONFIGURE=	yes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/server.tglpub \
			${PKG_SYSCONFDIR}/${PKGBASE}/server.tglpub

INSTALLATION_DIRS+=	${EGDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE}

SUBST_CLASSES+=		tglpub
SUBST_STAGE.tglpub=	pre-configure
SUBST_MESSAGE.tglpub=	Adjust path to server.tglpub
SUBST_FILES.tglpub=	telegram-purple.c
SUBST_SED.tglpub=	-e "s|/etc/|${PKG_SYSCONFDIR}/|g"

post-install:
	${INSTALL_DATA} ${WRKSRC}/tg-server.tglpub ${DESTDIR}${EGDIR}/server.tglpub

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
