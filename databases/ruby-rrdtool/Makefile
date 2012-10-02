# $NetBSD: Makefile,v 1.7 2012/10/02 17:10:44 tron Exp $
#

DISTNAME=	rrdtool-1.4.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	databases graphics net
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/rrdtool/
COMMENT=	Ruby binding for rrdtool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# rrdtool explicitly forbids any use of -ffast-math
#BUILDLINK_TRANSFORM+=	rm:-ffast-math

USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${DISTNAME}/bindings/ruby ${DISTNAME}/src
WRKSRC=			${WRKDIR}/${DISTNAME}/bindings/ruby

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
