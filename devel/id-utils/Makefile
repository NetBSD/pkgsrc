# $NetBSD: Makefile,v 1.12 2000/11/02 01:57:38 itojun Exp $
# FreeBSD Id: Makefile,v 1.4 1996/11/18 10:22:47 asami Exp
#

DISTNAME=	id-utils-3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=id-utils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/idutils/idutils.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

INFO_FILES=	id-utils.info
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes

.include "../../mk/bsd.pkg.mk"
