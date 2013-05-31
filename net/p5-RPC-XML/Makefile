# $NetBSD: Makefile,v 1.15 2013/05/31 12:41:41 wiz Exp $

DISTNAME=	RPC-XML-0.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blackperl.com/RPC::XML/
#HOMEPAGE=	http://search.cpan.org/dist/RPC-XML/
COMMENT=	XML-RPC client and server library for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10,p5-PathTools>=0.8}:../../devel/p5-PathTools
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.2}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-XML-LibXML>=1.70:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-Parser>=2.31:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=5.834:../../www/p5-libwww
DEPENDS+=	p5-DateTime>=0.70:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-ISO8601>=0.07:../../time/p5-DateTime-Format-ISO8601

USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/RPC/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
