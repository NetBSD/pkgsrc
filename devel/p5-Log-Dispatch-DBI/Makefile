# $NetBSD: Makefile,v 1.1.1.1 2004/06/30 07:00:49 grant Exp $

DISTNAME=	Log-Dispatch-DBI-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for logging messages via the DBI interface

DEPENDS+=	p5-DBD-CSV-[0-9]*:../../databases/p5-DBD-CSV
DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch

USE_BUILDLINK3=	yes
USE_LANGUAGES=	# empty

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Log/Dispatch/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
