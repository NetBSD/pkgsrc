# $NetBSD: Makefile,v 1.1.1.1 2002/01/03 14:02:27 agc Exp $

DISTNAME=		autoconf-2.52
PKGNAME=		autoconf-devel-2.52
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts

DEPENDS=		m4-1.4:../../devel/m4

CONFLICTS=		autoconf-[0-9]*

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		AWK="${AWK}"
M4=			${PREFIX}/bin/gm4

INFO_FILES=		autoconf.info standards.info

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
