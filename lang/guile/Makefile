# $NetBSD: Makefile,v 1.7 1998/11/15 20:17:56 perry Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=	guile-1.3
CONFLICTS=	guile-1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	perry@piermont.com
HOMEPAGE=	http://www.gnu.org/software/guile/guile.html

USE_LIBTOOL=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS="-Dunix" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
