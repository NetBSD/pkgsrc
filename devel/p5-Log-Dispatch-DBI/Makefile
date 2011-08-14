# $NetBSD: Makefile,v 1.10 2011/08/14 12:26:15 obache Exp $

DISTNAME=	Log-Dispatch-DBI-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for logging messages via the DBI interface

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBD-CSV-[0-9]*:../../databases/p5-DBD-CSV
DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Log/Dispatch/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
