# $NetBSD: Makefile,v 1.4 2016/09/12 16:09:52 taca Exp $

DISTNAME=	Net_LDAP3-1.0.5
MASTER_SITES=	${MASTER_SITE_LOCAL}
CATEGORIES+=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Object oriented interface for searching and manipulating LDAP-entries
HOMEPAGE=	https://git.kolab.org/project/profile/27/
LICENSE=	gnu-lgpl-v3

DEPENDS+=      ${PHP_PKG_PREFIX}-ldap>=5.2.12:../../databases/php-ldap

PEAR_PACKAGE_XML=	no

NO_CONFIGURE=	yes
USE_TOOLS+=	pax

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
