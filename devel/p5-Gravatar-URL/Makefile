# $NetBSD: Makefile,v 1.10 2018/08/22 09:44:06 wiz Exp $
#

DISTNAME=		Gravatar-URL-1.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSCHWERN/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Gravatar-URL/
COMMENT=		Make URLs for Gravatars from an email address
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
#DEPENDS+=		{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
#DEPENDS+=		{perl>=5.9.3,p5-Digest-SHA-[0-9]*}:../../security/p5-Digest-SHA

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Gravatar/URL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
