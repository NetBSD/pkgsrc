# $NetBSD: Makefile,v 1.13 1999/05/20 20:09:51 tron Exp $
# FreeBSD Id: Makefile,v 1.12 1997/11/22 16:01:32 jseger Exp
#

DISTNAME=	guile-1.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	perry@piermont.com
HOMEPAGE=	http://www.gnu.org/software/guile/guile.html

USE_LIBTOOL=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS="-Dunix"

INFO_FILES=	data-rep.info

.include "../../mk/bsd.pkg.mk"
