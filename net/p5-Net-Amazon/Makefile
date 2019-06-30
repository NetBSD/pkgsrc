# $NetBSD: Makefile,v 1.21 2019/06/30 20:16:26 nia Exp $

DISTNAME=	Net-Amazon-0.62
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Amazon
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-Simple>=2.08:../../textproc/p5-XML-Simple
DEPENDS+=	p5-Log-Log4perl>=0.30:../../devel/p5-Log-Log4perl
#DEPENDS+=	{perl>=5.007.003,p5-Time-HiRes>=1}:../../time/p5-Time-HiRes

PERL5_PACKLIST= auto/Net/Amazon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
