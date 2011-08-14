# $NetBSD: Makefile,v 1.4 2011/08/14 15:14:15 obache Exp $
#

DISTNAME=	Text-Unidecode-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Unidecode/
COMMENT=	Perl5 module that transliterates Unicode to US-ASCII

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Unidecode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
