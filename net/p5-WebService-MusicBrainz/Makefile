# $NetBSD: Makefile,v 1.2 2015/06/12 10:50:51 wiz Exp $

DISTNAME=		WebService-MusicBrainz-0.93
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WebService/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/WebService-MusicBrainz/
COMMENT=		Perl 5 module providing an interface to MusicBrainz
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=		p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/WebService/MusicBrainz/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
