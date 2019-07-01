# $NetBSD: Makefile,v 1.3 2019/07/01 21:35:52 nia Exp $

DISTNAME=	Data-Password-passwdqc-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://cpan.metacpan.org/authors/id/S/SH/SHERWIN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SH/SHERWIN/
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
