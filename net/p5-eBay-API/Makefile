# $NetBSD: Makefile,v 1.12 2013/12/09 14:17:50 obache Exp $

DISTNAME=		eBay-API-0.25
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TK/TKEEFER/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/eBay-API/
COMMENT=		Non SOAP based XML schema library for eBay API

DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=1.41
DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-Devel-StackTrace>=1.03:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Error>=0.15:../../devel/p5-Error
DEPENDS+=	p5-Exception-Class>=1.14:../../devel/p5-Exception-Class
DEPENDS+=  	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=  	p5-ParallelUserAgent>=2.57:../../www/p5-ParallelUserAgent
DEPENDS+=  	p5-Params-Validate>=0.74:../../devel/p5-Params-Validate
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.11}:../../devel/p5-Scalar-List-Utils
DEPENDS+=  	{perl>=5.10,p5-Time-HiRes>=1.51}:../../time/p5-Time-HiRes
DEPENDS+=  	p5-XML-Simple>=2.09:../../textproc/p5-XML-Simple
DEPENDS+=  	p5-XML-Tidy>=1.2.54:../../textproc/p5-XML-Tidy
DEPENDS+=  	p5-XML-Writer>=0.600:../../textproc/p5-XML-Writer

USE_TOOLS+=	gmake
REPLACE_PERL+=	*/*/*.pl */*/*/*/*/*.pl  */*/*/*/*/*/*.pl */*/*/*/*/*/*/*.pl
REPLACE_PERL+=	*/*.t */*/*/*/*/*.t */*/*/*/*/*/*.t
REPLACE_PERL+=	*/*/*/*.pm */*/*/*/*.pm */*/*/*/*/*.pm  */*/*/*/*/*/*.pm
REPLACE_PERL+=	*/*/*/*/*/*/*/*.pm

PERL5_PACKLIST=		auto/eBay/API/.packlist

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
