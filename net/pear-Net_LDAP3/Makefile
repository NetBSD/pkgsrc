# $NetBSD: Makefile,v 1.1 2015/06/06 05:26:55 manu Exp $

DISTNAME=	Net_LDAP3-1.0.3
PKGNAME=	pear-${DISTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	pear
MASTER_SITES=	${MASTER_SITE_LOCAL}
CATEGORIES+=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface for searching and manipulating LDAP-entries
LICENSE=	gnu-lgpl-v3

PEAR_LIB=	lib/php		# duplicate from ../../langf/php/pear.mk
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

DEPENDS+=      ${PHP_PKG_PREFIX}-ldap>=5.2.12:../../databases/php-ldap

do-install:
	cd ${WRKSRC}/lib && ${PAX} -wr * ${DESTDIR}${PREFIX}/${PEAR_LIB}/

PLIST_SUBST+=	PEAR_LIB=${PEAR_LIB:Q}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
