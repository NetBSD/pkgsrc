# $NetBSD: Makefile,v 1.2 1998/07/17 19:39:42 tv Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=	guile-1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	perry@piermont.com

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

GNU_CONFIGURE=	YES
CONFIGURE_ENV=	LIBTOOL=${PREFIX}/bin/libtool \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
