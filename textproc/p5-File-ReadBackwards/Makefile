# $NetBSD: Makefile,v 1.3 2010/08/21 16:35:52 seb Exp $
#

DISTNAME=		File-ReadBackwards-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-ReadBackwards/
COMMENT=		Perl 5 module to read a file backwards by lines

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/File/ReadBackwards/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
