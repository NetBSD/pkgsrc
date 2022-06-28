# $NetBSD: Makefile,v 1.21 2022/06/28 11:31:52 wiz Exp $

DISTNAME=	AnyEvent-XMPP-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTPLBG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/AnyEvent::XMPP
COMMENT=	Implementation of the XMPP Protocol
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AnyEvent>=0:../../devel/p5-AnyEvent
DEPENDS+=	p5-Authen-SASL>=0:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Net-LibIDN>=0:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Object-Event>=0.7:../../devel/p5-Object-Event
#DEPENDS+=	{perl>=5.14.0,p5-Time-Local>=0}:../../time/p5-Time-Local
DEPENDS+=	p5-XML-Writer>=0:../../textproc/p5-XML-Writer

PERL5_PACKLIST=	auto/AnyEvent/XMPP/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
