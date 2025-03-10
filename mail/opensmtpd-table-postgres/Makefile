# $NetBSD: Makefile,v 1.2 2025/03/10 07:20:54 vins Exp $

DISTNAME=	table-postgres-1.1.1
PKGREVISION=	1
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=opensmtpd/}
GITHUB_PROJECT=	table-postgres
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/opensmtpd/table-postgres
COMMENT=	OpenSMTPD PostgreSQL table add-on
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

.include "../../mk/pgsql.buildlink3.mk"

BUILDLINK_INCDIRS.${PGSQL_TYPE}=	include/postgresql

.include "../../mk/bsd.pkg.mk"
