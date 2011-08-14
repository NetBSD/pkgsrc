# $NetBSD: Makefile,v 1.6 2011/08/14 12:26:04 obache Exp $
#

DISTNAME=	RTx-RightsMatrix-0.03.00
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RTx/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~htchapman/RTx-RightsMatrix/
COMMENT=	Utility to efficiently manage rights to a RT installation

DEPENDS+=	rt>=3.4.5:../../devel/rt3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_ENV+=	DESTDIR=${DESTDIR}

.include "../../devel/rt3/dirs.mk"

PLIST_SUBST+=		RT_SHARE_DIR=share/rt3

PERL5_PACKLIST=		auto/RTx/RightsMatrix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
