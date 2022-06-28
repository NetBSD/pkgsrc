# $NetBSD: Makefile,v 1.20 2022/06/28 11:35:43 wiz Exp $
#

DISTNAME=	Crypt-PasswdMD5-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Crypt-PasswdMD5
COMMENT=	MD5-based crypt() function
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Crypt/PasswdMD5/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
