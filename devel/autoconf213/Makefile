# $NetBSD: Makefile,v 1.1.1.1 2002/10/03 19:25:04 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.13
PKGNAME=	autoconf213-2.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=	Generates automatic source code configuration scripts

DEPENDS=	m4-1.4:../../devel/m4

CONFLICTS=		autoconf-devel-[0-9]*
CONFLICTS=		autoconf<2.50

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		AWK="${AWK}"
CONFIGURE_ARGS+=	--program-transform-name='s/$$/-2.13/'
M4=			${PREFIX}/bin/gm4

INFO_FILES=		autoconf213.info
TEXINFO_OVERRIDE=	YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
