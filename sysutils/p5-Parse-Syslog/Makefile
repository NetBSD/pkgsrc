# $NetBSD: Makefile,v 1.1.1.1 2006/07/16 09:54:10 heinz Exp $
#

DISTNAME=		Parse-Syslog-1.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5psl
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Parse-Syslog/
COMMENT=		Perl5 module for parsing Unix syslog files

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Parse/Syslog/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
