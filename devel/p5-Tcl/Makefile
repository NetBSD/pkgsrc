# $NetBSD: Makefile,v 1.1 2025/01/31 01:41:29 scole Exp $

DISTNAME=	Tcl-1.51
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 tcl
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Tcl
COMMENT=	Tcl extension module for Perl
LICENSE=	${PERL5_LICENSE}

# xxx for an unusual platform that won't build, maybe?
# MAKE_PARAMS+=	--nousestubs

MAKE_PARAMS+=	--tclconfig ${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh

PERL5_PACKLIST=		auto/Tcl/.packlist

.include "../../lang/perl5/module.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
