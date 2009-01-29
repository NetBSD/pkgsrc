# $NetBSD: Makefile,v 1.1.1.1 2009/01/29 22:00:17 seb Exp $
#

DISTNAME=	Cisco-Abbrev-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cisco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cisco-Abbrev/
COMMENT=	Perl 5 module to translate to/from Cisco interface abbbreviations

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Cisco/Abbrev/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
