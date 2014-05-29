# $NetBSD: Makefile,v 1.8 2014/05/29 23:37:09 wiz Exp $
#

DISTNAME=	Net-XMPP-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	chat perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~hacker/Net-XMPP-1.02/
COMMENT=	Provide a Perl Developer access to the XMPP protocol

DEPENDS+=	p5-XML-Stream>=1.22:../../textproc/p5-XML-Stream
DEPENDS+=	p5-Digest-SHA1>=1.02:../../security/p5-Digest-SHA1

PERL5_MODULE_TYPE= Module::Build
PERL5_PACKLIST=	auto/Net/XMPP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
