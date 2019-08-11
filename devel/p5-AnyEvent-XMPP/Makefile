# $NetBSD: Makefile,v 1.15 2019/08/11 13:18:50 wiz Exp $
#

DISTNAME=	AnyEvent-XMPP-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MS/MSTPLBG/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/E/EL/ELMEX/
COMMENT=	Implementation of the XMPP Protocol
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AnyEvent>=0:../../devel/p5-AnyEvent
DEPENDS+=	p5-Authen-SASL>=0:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-LibIDN>=0:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Object-Event>=0.7:../../devel/p5-Object-Event
#DEPENDS+=	{perl>=5.14.0,p5-Time-Local>=0}:../../time/p5-Time-Local
DEPENDS+=	p5-XML-Writer>=0:../../textproc/p5-XML-Writer

PERL5_PACKLIST=	auto/AnyEvent/XMPP/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
