# $NetBSD: Makefile,v 1.1.1.1 2000/11/29 18:28:30 wiz Exp $
#

DISTNAME=	guile-oops-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=guile/}

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.gnu.org/software/guile/

DEPENDS+=	guile>=1.3.2:../../lang/guile

GNU_CONFIGURE=		YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

# XXX: are these symlinks needed?  how do I include the second in PLIST?

post-install:
	${RM} ${PREFIX}/share/guile/oop/goops/libgoopscore.la
	${RM} ${PREFIX}/share/guile/oop/goops/libgoopscore.so.4

.include "../../mk/bsd.pkg.mk"
