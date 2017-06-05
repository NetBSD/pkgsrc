# $NetBSD: Makefile,v 1.15 2017/06/05 14:24:36 ryoon Exp $
#

DISTNAME=		Parse-Syslog-1.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		sysutils perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Parse-Syslog/
COMMENT=		Perl5 module for parsing Unix syslog files

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Parse/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
