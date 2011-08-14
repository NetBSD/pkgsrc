# $NetBSD: Makefile,v 1.12 2011/08/14 14:14:42 obache Exp $

DISTNAME=	Net-Amazon-S3-0.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-Amazon-S3/
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Data-Stream-Bulk>=0:../../net/p5-Data-Stream-Bulk
DEPENDS+=	p5-DateTime-Format-HTTP>=0:../../time/p5-DateTime-Format-HTTP
DEPENDS+=	p5-DateTime-Format-ISO8601>=0:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-MD5-File>=0:../../security/p5-Digest-MD5-File
DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	{perl>=5.10.0,p5-IO>=0.14}:../../devel/p5-IO
DEPENDS+=	p5-LWP-UserAgent-Determined>=0:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-StrictConstructor>=0:../../devel/p5-MooseX-StrictConstructor
DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML

PERL5_PACKLIST= auto/Net/Amazon/S3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
