# $NetBSD: Makefile,v 1.15 2018/08/22 09:46:23 wiz Exp $
#

DISTNAME=	Crypt-PasswdMD5-1.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/
COMMENT=	MD5-based crypt() function
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Crypt/PasswdMD5/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
