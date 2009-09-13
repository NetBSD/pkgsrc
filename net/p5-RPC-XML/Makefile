# $NetBSD: Makefile,v 1.7 2009/09/13 19:25:53 sno Exp $

DISTNAME=	RPC-XML-0.69
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blackperl.com/RPC::XML/
#HOMEPAGE=	http://search.cpan.org/dist/RPC-XML/
COMMENT=	XML-RPC client and server library for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10,p5-PathTools>=0.8}:../../devel/p5-PathTools
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.2}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-XML-Parser>=2.31:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=5.801:../../www/p5-libwww

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/RPC/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
