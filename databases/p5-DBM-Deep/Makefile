# $NetBSD: Makefile,v 1.1.1.1 2008/08/23 20:10:02 seb Exp $

DISTNAME=	DBM-Deep-1.0013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBM-Deep/
COMMENT=	Pure perl multi-level hash/array DBM that supports transactions

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/DBM/Deep/.packlist

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Test-Deep>=0.095:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Warn>=0.08:../../devel/p5-Test-Warn

# for test target
BUILD_DEPENDS+=	p5-FileHandle-Fmode-[0-9]*:../../devel/p5-FileHandle-Fmode

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
