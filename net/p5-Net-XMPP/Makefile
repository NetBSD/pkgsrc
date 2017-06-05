# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:23 ryoon Exp $
#

DISTNAME=	Net-XMPP-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~hacker/Net-XMPP-1.02/
COMMENT=	Provide a Perl Developer access to the XMPP protocol
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-XML-Stream>=1.24:../../textproc/p5-XML-Stream
DEPENDS+=	p5-Digest-SHA1>=1.02:../../security/p5-Digest-SHA1

PERL5_MODULE_TYPE= Module::Build
PERL5_PACKLIST=	auto/Net/XMPP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
