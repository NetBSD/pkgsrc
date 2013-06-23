# $NetBSD: Makefile,v 1.7 2013/06/23 12:18:34 pettai Exp $
#

DISTNAME=	fpdns-20130404
PKGNAME=	fpdns-0.10.0pre20130404
CATEGORIES=	net
MASTER_SITES=	-https://github.com/kirei/fpdns/archive/20130404.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kirei/fpdns/
COMMENT=	Fingerprinting DNS servers
LICENSE=	modified-bsd

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS

FETCH_USING=	curl

REPLACE_PERL=	apps/fpdns
USE_TOOLS+=	perl
USE_LANGUAGES=	# none

PERL5_CONFIGURE=	yes
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
