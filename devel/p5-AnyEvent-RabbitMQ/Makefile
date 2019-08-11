# $NetBSD: Makefile,v 1.13 2019/08/11 13:18:50 wiz Exp $

DISTNAME=	AnyEvent-RabbitMQ-1.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DL/DLAMBLEY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnyEvent-RabbitMQ
COMMENT=	RabbitMQ interface with AnyEvent
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Net-AMQP>=0.06:../../net/p5-Net-AMQP
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=	p5-XML-LibXML>=2:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

EXTRACT_USING=	bsdtar
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/AnyEvent/RabbitMQ/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
