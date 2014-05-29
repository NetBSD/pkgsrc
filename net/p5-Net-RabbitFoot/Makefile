# $NetBSD: Makefile,v 1.4 2014/05/29 23:37:09 wiz Exp $

DISTNAME=	Net-RabbitFoot-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/I/IK/IKUTA/
MASTER_SITES+=	http://cpan.metacpan.org/authors/id/I/IK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/I/IK/IKUTA/
COMMENT=        Asynchronous and multi channel Perl AMQP client
LICENSE=        ${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Install::Bundled
DEPENDS+=       p5-AnyEvent>=0:../../devel/p5-AnyEvent
DEPENDS+=       p5-AnyEvent-RabbitMQ>=0:../../devel/p5-AnyEvent-RabbitMQ
DEPENDS+=       p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=       p5-MooseX-AttributeHelpers>=0.20:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=       p5-MooseX-ConfigFromFile>=0.10:../../devel/p5-MooseX-ConfigFromFile
DEPENDS+=       p5-MooseX-App-Cmd>=0.20:../../devel/p5-MooseX-App-Cmd
DEPENDS+=       p5-Config-Any>=0.20:../../devel/p5-Config-Any
DEPENDS+=       p5-Coro>=6:../../devel/p5-Coro
DEPENDS+=       p5-Moose>=2:../../devel/p5-Moose

PERL5_PACKLIST=	auto/Net/RabbitFoot/.packlist
REPLACE_PERL+=	rabbit_foot

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
