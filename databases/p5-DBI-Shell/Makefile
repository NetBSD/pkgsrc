# $NetBSD: Makefile,v 1.1.1.1 2004/02/22 01:38:58 minskim Exp $
#

DISTNAME=	DBI-Shell-11.9
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.perldoc.com/perl5.6.1/lib/DBI/Shell.html
COMMENT=	Interactive command Shell for the Perl DBI

DEPENDS+=	p5-IO-Tee>=0.64:../../devel/p5-IO-Tee
DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBI/Shell/.packlist

BUILDLINK_DEPENDS.p5-DBI+=	p5-DBI>=1.37

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
