# $NetBSD: Makefile,v 1.4 2012/10/03 21:55:11 wiz Exp $
#

DISTNAME=		Internals-1.1
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
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
