# $NetBSD: Makefile,v 1.6 2011/08/14 14:42:48 obache Exp $
#

DISTNAME=	Crypt-PasswdMD5-1.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.cpan.org/pub/CPAN/modules/by-module/Crypt/
COMMENT=	MD5-based crypt() function

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Crypt/PasswdMD5/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
