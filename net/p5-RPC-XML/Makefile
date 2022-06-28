# $NetBSD: Makefile,v 1.32 2022/06/28 11:35:16 wiz Exp $

DISTNAME=	RPC-XML-0.82
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.blackperl.com/RPC::XML/
#HOMEPAGE=	http://search.cpan.org/dist/RPC-XML/
COMMENT=	XML-RPC client and server library for Perl
LICENSE=	${PERL5_LICENSE}

# if Net::Server exists, t/60 may fail due to more test items
# t/60_net_server.t ............... skipped: Net::Server not available
#EPENDS+=	p5-Net-Server-[0-9]*:../../net/p5-Net-Server
DEPENDS+=	p5-XML-LibXML>=1.85:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-Parser>=2.31:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=5.834:../../www/p5-libwww
DEPENDS+=	p5-DateTime>=0.70:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-ISO8601>=0.07:../../time/p5-DateTime-Format-ISO8601

USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty

SUBST_CLASSES+=		usebase
SUBST_STAGE.usebase=	pre-configure
SUBST_FILES.usebase=	lib/RPC/XML.pm
SUBST_SED.usebase=	-e "s|^use base 'RPC::XML::|use parent -norequire, 'RPC::XML::|g"

PERL5_PACKLIST=		auto/RPC/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
