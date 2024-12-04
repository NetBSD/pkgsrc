# $NetBSD: Makefile,v 1.1 2024/12/04 22:54:17 vins Exp $

DISTNAME=	table-passwd-1.0.2
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=opensmtpd/}
GITHUB_PROJECT=	table-passwd
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/opensmtpd/table-passwd
COMMENT=	OpenSMTPD passwd table add-on
LICENSE=	isc

CONFLICTS+=	opensmtpd-extras-[0-9]*
DEPENDS+=	opensmtpd>=7.6.0:../../mail/opensmtpd

USE_TOOLS+=	autoconf automake autoreconf

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		dir
SUBST_STAGE.dir=	pre-configure
SUBST_MESSAGE.dir=	Fixing smtpdir for pkgsrc.
SUBST_FILES.dir=	Makefile.am
SUBST_SED.dir+=		-e "s:libexec/smtpd:libexec/opensmtpd:g"

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
