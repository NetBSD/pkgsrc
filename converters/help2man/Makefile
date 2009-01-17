# $NetBSD: Makefile,v 1.1.1.1 2009/01/17 20:43:27 wiz Exp $
#

DISTNAME=		help2man-1.36.4
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=help2man/}

MAINTAINER=		arved@arved.at
HOMEPAGE=		http://www.gnu.org/software/help2man/
COMMENT=		Generate simple manual pages from program output

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run msgfmt gmake

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
