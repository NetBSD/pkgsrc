# $NetBSD: Makefile,v 1.22 2020/04/12 08:28:34 adam Exp $

DISTNAME=	starbug1-1.6.01
PKGREVISION=	19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSDN:=starbug1/57514/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://starbug1.com/
COMMENT=	Light weight Bug Tracking System written in C and Perl
LICENSE=	gnu-gpl-v2

.include "options.mk"

BUILD_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
BUILD_DEPENDS+=	p5-Locale-PO-[0-9]*:../../devel/p5-Locale-PO
BUILD_DEPENDS+=	rsync-[0-9]*:../../net/rsync

DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck

USE_TOOLS+=	gmake msgfmt pax perl

# Build tool
REPLACE_PERL+=	bin/po2json

# Installed programs
REPLACE_PERL+=	check.cgi
REPLACE_PERL+=	script/*.pl

BUILD_TARGET=	webapp

.include "../../mk/bsd.prefs.mk"

SB_DIR=		share/starbug1

CONF_FILES+=	${SB_DIR}/dot.htaccess ${SB_DIR}/.htaccess

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		SB_DIR=${SB_DIR}

INSTALLATION_DIRS=	share

do-install:
	chmod 644 ${WRKSRC}/dist/starbug1/debug.log
	cd ${WRKSRC}/dist && ${FIND} starbug1 -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=sqlite3>=3.7.17
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../www/cgic/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
