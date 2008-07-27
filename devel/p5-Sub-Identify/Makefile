# $NetBSD: Makefile,v 1.2 2008/07/27 22:37:54 seb Exp $
#

DISTNAME=	Sub-Identify-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Identify/
COMMENT=	Perl 5 module to retrieve names of code references

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Sub/Identify/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
