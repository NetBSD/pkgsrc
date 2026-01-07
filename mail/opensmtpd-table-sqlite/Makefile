# $NetBSD: Makefile,v 1.4 2026/01/07 08:47:48 wiz Exp $

DISTNAME=	table-sqlite-1.0.1
PKGREVISION=	3
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=opensmtpd/}
GITHUB_PROJECT=	table-sqlite
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/opensmtpd/table-sqlite
COMMENT=	OpenSMTPD SQLite3 table add-on
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
	${RUN}set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
