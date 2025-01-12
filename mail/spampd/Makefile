# $NetBSD: Makefile,v 1.1 2025/01/12 00:21:47 jakllsch Exp $

SPAMPD_VERSION=	2.62
GITHUB_PROJECT=	spampd
GITHUB_TAG=	refs/tags/${SPAMPD_VERSION}
DISTNAME=	${SPAMPD_VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spampd.pl ${DESTDIR}${PREFIX}/sbin/spampd

.include "../../mk/bsd.pkg.mk"
