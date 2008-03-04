# $NetBSD: Makefile,v 1.2 2008/03/04 11:02:25 rillig Exp $
#

DISTNAME=	Crypt-PasswdMD5-1.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/
COMMENT=	MD5-based crypt() function

PERL5_PACKLIST=	auto/Crypt/PasswdMD5/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
