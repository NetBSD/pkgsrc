# $NetBSD: Makefile,v 1.11 2013/05/31 12:40:41 wiz Exp $
#

DISTNAME=		Proc-ProcessTable-0.45
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-ProcessTable/
COMMENT=		Perl extension to access the UNIX process table

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL=		example.pl

PERL5_PACKLIST=		auto/Proc/ProcessTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
