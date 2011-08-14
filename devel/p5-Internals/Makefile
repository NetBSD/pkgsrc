# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:13 obache Exp $
#

DISTNAME=		Internals-1.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
#MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Internals/} # XXX doesn't work
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/S/ST/STBEY/


MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Internals/
COMMENT=		Write-protect Perl variables, manipulate refcounts

USE_LANGUAGES=		c
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Internals/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
