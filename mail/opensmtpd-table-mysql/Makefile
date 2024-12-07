# $NetBSD: Makefile,v 1.2 2024/12/07 20:37:34 vins Exp $

DISTNAME=	table-mysql-1.2.1
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=opensmtpd/}
GITHUB_PROJECT=	table-mysql
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/opensmtpd/table-mysql
COMMENT=	OpenSMTPD MySQL table add-on
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

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
