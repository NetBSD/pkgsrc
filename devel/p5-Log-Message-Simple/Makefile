# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:28 wiz Exp $

DISTNAME=	Log-Message-Simple-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Log::Message::Simple
COMMENT=	Simple - Simplified interface to Log::Message
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Log-Message-[0-9]*:../../devel/p5-Log-Message

PERL5_PACKLIST=	auto/Log/Message/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
