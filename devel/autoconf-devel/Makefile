# $NetBSD: Makefile,v 1.6 2002/08/08 11:34:36 wiz Exp $

DISTNAME=		autoconf-2.53
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=autoconf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/autoconf/autoconf.html
COMMENT=		Generates automatic source code configuration scripts

DEPENDS=		m4-1.4:../../devel/m4

CONFLICTS=		autoconf-devel-[0-9]*

USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-lispdir
CONFIGURE_ENV+=		AWK="${AWK}"
M4=			${PREFIX}/bin/gm4

INFO_FILES=		autoconf.info standards.info

PERL5_REQD=		5.6
TEXINFO_REQD=		4.0

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
