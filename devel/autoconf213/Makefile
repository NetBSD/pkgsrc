# $NetBSD: Makefile,v 1.8 2004/01/05 23:20:29 jlam Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.13
PKGNAME=	autoconf213-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts (old version)

DEPENDS=	m4>=1.4:../../devel/m4

CONFLICTS=		autoconf-devel-[0-9]*
CONFLICTS=		autoconf<2.50

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		AWK="${AWK}"
CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.13/'
M4=			${LOCALBASE}/bin/gm4

USE_MAKEINFO=		YES
INFO_FILES=		autoconf213.info

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
