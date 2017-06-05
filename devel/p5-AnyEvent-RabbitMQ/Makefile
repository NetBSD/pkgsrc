# $NetBSD: Makefile,v 1.8 2017/06/05 14:22:34 ryoon Exp $

DISTNAME=	AnyEvent-RabbitMQ-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://cpan.metacpan.org/CPAN/authors/id/B/BO/BOBTFISH/
MASTER_SITES+=	http://cpan.metacpan.org/authors/id/B/BO/BOBTFISH/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BO/BOBTFISH/
COMMENT=	RabbitMQ interface with AnyEvent
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AnyEvent>=0:../../devel/p5-AnyEvent
DEPENDS+=	p5-Net-AMQP>=0.06:../../net/p5-Net-AMQP
DEPENDS+=	p5-XML-LibXML>=2:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Devel-GlobalDestruction>=0.12:../../devel/p5-Devel-GlobalDestruction

EXTRACT_USING=	gtar
PERL5_PACKLIST=	auto/AnyEvent/RabbitMQ/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
