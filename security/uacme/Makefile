# $NetBSD: Makefile,v 1.2 2024/05/16 06:15:32 wiz Exp $

PKGNAME=	uacme-${PKGVER}
PKGREVISION=	1
DISTNAME=	v${PKGVER}
PKGVER=		1.7.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=ndilieto/uacme/archive/refs/tags/}

MAINTAINER=	hauke@NetBSD.org
COMMENT=	Lightweight C ACMEv2 client which uses external authenticators
HOMEPAGE=	https://github.com/ndilieto/uacme
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=		gmake pkg-config autoconf autoreconf automake

USE_LANGUAGES=		c
USE_CC_FEATURES=	c11

GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/uacme-${PKGVER}

HOOKDIR=		libexec
DOCDIR=			share/doc/uacme
UACME_CONFDIR=		${VARBASE}/uacme
UACME_CHALLENGE_PATH=	${UACME_CONFDIR}/challenge

CONFIGURE_ARGS=		--datadir=${PREFIX}/${HOOKDIR}
CONFIGURE_ARGS+=	--disable-maintainer-mode
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILD_DEFS+=		VARBASE

.include "options.mk"

REPLACE_SH+=			nsupdate.sh uacme.sh ualpn.sh

MESSAGE_SUBST+=			UACME_CHALLENGE_PATH=${UACME_CHALLENGE_PATH}

SUBST_CLASSES+=			confdir
SUBST_STAGE.confdir=		pre-configure
SUBST_MESSAGE.confdir=		Set CONFDIR default
SUBST_FILES.confdir=		uacme.c
SUBST_VARS.confdir=		UACME_CONFDIR

SUBST_CLASSES+=			challenge
SUBST_STAGE.challenge=		pre-configure
SUBST_MESSAGE.challenge=	Set http-01 challenge default directory
SUBST_FILES.challenge=		uacme.sh
SUBST_VARS.challenge=		UACME_CHALLENGE_PATH

INSTALLATION_DIRS+=		${HOOKDIR}/uacme ${DOCDIR}

OWN_DIRS=			${UACME_CONFDIR} ${UACME_CHALLENGE_PATH}
OWN_DIRS_PERMS+=		${UACME_CONFDIR}/private ${REAL_ROOT_USER} \
					${REAL_ROOT_GROUP} 0700

pre-configure:
	cd ${WRKSRC} && autoreconf -if

post-install:
	${INSTALL_MAN} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
