# $NetBSD: Makefile,v 1.10 1999/02/20 22:48:32 hubertf Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=	guile-1.3
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

INFO_FILES=	data-rep.info

.include "../../mk/bsd.pkg.mk"
