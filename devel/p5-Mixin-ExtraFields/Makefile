# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:17 obache Exp $
#

DISTNAME=	Mixin-ExtraFields-0.100971
PKGNAME=	p5-Mixin-ExtraFields-0.100.971
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mixin-ExtraFields/
COMMENT=	Perl 5 module to add extra stashes of data to your objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-String-RewritePrefix-[0-9]*:../../textproc/p5-String-RewritePrefix
DEPENDS+=	p5-Sub-Exporter>=0.972:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install

PERL5_PACKLIST=	auto/Mixin/ExtraFields/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
