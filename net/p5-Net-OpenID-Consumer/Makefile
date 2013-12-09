# $NetBSD: Makefile,v 1.13 2013/12/09 14:17:50 obache Exp $
#

DISTNAME=	Net-OpenID-Consumer-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-OpenID-Consumer/
COMMENT=	Perl library for consumers of OpenID identities
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Crypt-DH>=0.05:../../security/p5-Crypt-DH
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	{perl>=5.14.0,p5-Time-Local-[0-9]*}:../../time/p5-Time-Local
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PERL5_PACKLIST=		auto/Net/OpenID/Consumer/.packlist
USE_LANGUAGES=		# none

REPLACE_PERL+=		lib/Net/OpenID/URIFetch.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
