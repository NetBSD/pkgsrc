# $NetBSD: Makefile,v 1.1.1.1 2012/04/12 23:57:24 mspo Exp $
#

DISTNAME=	AnyEvent-XMPP-0.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/E/EL/ELMEX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/E/EL/ELMEX/
COMMENT=	Implementation of the XMPP Protocol
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-AnyEvent>=0:../../devel/p5-AnyEvent
DEPENDS+=	p5-Authen-SASL>=0:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-SHA1>=0:../../security/p5-Digest-SHA1
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Net-LibIDN>=0:../../net/p5-Net-LibIDN
DEPENDS+=	p5-Object-Event>=0.7:../../devel/p5-Object-Event
DEPENDS+=	p5-Time-Local>=0:../../time/p5-Time-Local
DEPENDS+=	p5-XML-Writer>=0:../../textproc/p5-XML-Writer

PERL5_PACKLIST=	auto/AnyEvent/XMPP/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
