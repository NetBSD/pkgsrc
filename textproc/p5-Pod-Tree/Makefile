# $NetBSD: Makefile,v 1.31 2023/07/06 09:41:44 wiz Exp $

DISTNAME=	Pod-Tree-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-Tree
COMMENT=	Create a static syntax tree for a POD
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Stream>=1.49:../../www/p5-HTML-Stream
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
#DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.02}:../../textproc/p5-Pod-Escapes
DEPENDS+=	p5-Text-Template>=1.0:../../textproc/p5-Text-Template

TOOL_DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny
TOOL_DEPENDS+=	p5-Test-Compile>=0:../../devel/p5-Test-Compile
TOOL_DEPENDS+=	p5-Test-Version>=1.003001:../../devel/p5-Test-Version

PERL5_PACKLIST=	auto/Pod/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
