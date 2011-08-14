# $NetBSD: Makefile,v 1.11 2011/08/14 14:14:48 obache Exp $

DISTNAME=	RPC-XML-0.73
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
DEPENDS+=	p5-libwww>=5.801:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/RPC/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
