# $NetBSD: Makefile,v 1.1.1.1 2009/12/05 21:36:40 seb Exp $
#

DISTNAME=	Format-Human-Bytes-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Format/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Format-Human-Bytes/
COMMENT=	Perl 5 module to format a bytecount and make it human readable

USE_LANGUAGES=		# empty
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Format/Human/Bytes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
