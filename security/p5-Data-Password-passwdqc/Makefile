# $NetBSD: Makefile,v 1.1 2018/03/11 12:08:18 maya Exp $

DISTNAME=	Data-Password-passwdqc-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SH/SHERWIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SH/SHERWIN/
COMMENT=	Perl5 check password strength and generate password using passwdqc
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=	p5-namespace-autoclean>=0:../../devel/p5-namespace-autoclean

PERL5_PACKLIST=	auto/Data/Password/passwdqc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
