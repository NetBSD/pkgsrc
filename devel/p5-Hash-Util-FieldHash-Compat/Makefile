# $NetBSD: Makefile,v 1.17 2019/06/30 20:15:08 nia Exp $
#

DISTNAME=	Hash-Util-FieldHash-Compat-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Hash-Util-FieldHash-Compat
COMMENT=	Perl 5 module to user Hash::Util::FieldHash or ties
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Util/FieldHash/Compat/.packlist

# This package was added after Perl 5.10 became the minimal required
# version for pkgsrc. The module Hash::Util::FieldHash is a core
# module since version 5.9.4. Thus this module/package does not need
# any of the two dependencies below.
#DEPENDS+= p5-Tie-RefHash>=1.38:../../devel/p5-Tie-RefHash
# ---------------------
# Data for 2015-06-01
# Tie::RefHash::Weak was not in CORE (or so I think)
DEPENDS+= p5-Tie-RefHash-Weak>=0.08:../../devel/p5-Tie-RefHash-Weak

BUILD_DEPENDS+=	p5-Test-Simple>=1.001010:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
