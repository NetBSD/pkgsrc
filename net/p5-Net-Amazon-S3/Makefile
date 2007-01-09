# $NetBSD: Makefile,v 1.1.1.1 2007/01/09 17:09:54 tv Exp $

DISTNAME=	Net-Amazon-S3-0.37
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	tv@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Amazon-S3/
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-DateTime-Format-Strptime>=0:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML

BUILD_DEPENDS+=	{perl>=5.8.0,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Net/Amazon/S3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
