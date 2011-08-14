# $NetBSD: Makefile,v 1.4 2011/08/14 14:14:41 obache Exp $
#

DISTNAME=	Cisco-Abbrev-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Cisco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Cisco-Abbrev/
COMMENT=	Perl 5 module to translate to/from Cisco interface abbbreviations
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Cisco/Abbrev/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
