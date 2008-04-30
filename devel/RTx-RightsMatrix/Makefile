# $NetBSD: Makefile,v 1.2 2008/04/30 10:20:20 cube Exp $
#

DISTNAME=	RTx-RightsMatrix-0.03.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RTx/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~htchapman/RTx-RightsMatrix/
COMMENT=	Utility to efficiently manage rights to a RT installation

DEPENDS+=	rt>=3.4.5:../../devel/rt3

.include "../../devel/rt3/dirs.mk"

PLIST_SUBST+=		RT_SHARE_DIR=share/rt3

PERL5_PACKLIST=		auto/RTx/RightsMatrix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
