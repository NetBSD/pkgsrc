# $NetBSD: Makefile,v 1.2 2025/03/03 14:51:59 jakllsch Exp $

SPAMPD_VERSION=	2.62
GITHUB_PROJECT=	spampd
GITHUB_TAG=	refs/tags/${SPAMPD_VERSION}
DISTNAME=	${SPAMPD_VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=mpaperno/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mpaperno/spampd/
COMMENT=	Spam mail policy daemon
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/spampd-${SPAMPD_VERSION}
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
REPLACE_PERL=	spampd.pl
NO_BUILD=	yes

DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
DEPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server

INSTALLATION_DIRS+=	sbin

RCD_SCRIPTS=	spampd
FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	SPAMPD_USER=${SPAMPD_USER}
FILES_SUBST+=	SPAMPD_GROUP=${SPAMPD_GROUP}

SPAMPD_USER?=	_spampd
SPAMPD_GROUP?=	_spampd
PKG_GROUPS=	${SPAMPD_GROUP}
PKG_USERS=	${SPAMPD_USER}:${SPAMPD_GROUP}
PKG_GROUPS_VARS+=	SPAMPD_GROUP
PKG_USERS_VARS+=	SPAMPD_USER
PKG_GECOS.${SPAMPD_USER}=spampd daemon user

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spampd.pl ${DESTDIR}${PREFIX}/sbin/spampd

.include "../../mk/bsd.pkg.mk"
