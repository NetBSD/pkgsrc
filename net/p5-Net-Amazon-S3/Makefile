# $NetBSD: Makefile,v 1.7 2008/11/18 06:24:54 he Exp $

DISTNAME=	Net-Amazon-S3-0.45
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Amazon-S3/
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-MD5-File>=0:../../security/p5-Digest-MD5-File
DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-LWP-UserAgent-Determined>=0:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML
DEPENDS+=	{perl>=5.10.0,p5-IO>=0.14}:../../devel/p5-IO

BUILD_DEPENDS+=	{perl>=5.8.0,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Net/Amazon/S3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
