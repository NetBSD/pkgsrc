# $NetBSD: Makefile,v 1.10 2023/07/06 09:41:25 wiz Exp $

DISTNAME=	Data-Password-passwdqc-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SH/SHERWIN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Data::Password::passwdqc
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
