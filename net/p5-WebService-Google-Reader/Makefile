# $NetBSD: Makefile,v 1.16 2019/06/30 20:16:34 nia Exp $
#

DISTNAME=		WebService-Google-Reader-0.23
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WebService/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/WebService-Google-Reader
COMMENT=		Perl 5 module providing an interface to Google Reader
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/WebService/Google/Reader/.packlist

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.82}:../../devel/p5-Test-Simple
DEPENDS+=	p5-JSON-XS>=2:../../converters/p5-JSON-XS
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Atom-[0-9]*:../../textproc/p5-XML-Atom
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
