# $NetBSD: Makefile,v 1.1 2020/11/22 11:58:58 nia Exp $

DISTNAME=	libpwquality-1.4.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=libpwquality/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libpwquality/libpwquality
COMMENT=	Library for generating random passwords and quality checking
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-pam
CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE=	src/pwquality.pc.in

PY_PATCHPLIST=	yes

OWN_DIRS+=	${PKG_SYSCONFDIR}/security

EGDIR=		share/examples/libpwquality

CONF_FILES=	${EGDIR}/security/pwquality.conf \
		${PKG_SYSCONFDIR}/security/pwquality.conf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/cracklib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
