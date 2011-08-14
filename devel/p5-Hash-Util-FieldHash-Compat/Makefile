# $NetBSD: Makefile,v 1.3 2011/08/14 12:26:09 obache Exp $
#

DISTNAME=	Hash-Util-FieldHash-Compat-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-Util-FieldHash-Compat/
COMMENT=	Perl 5 module to user Hash::Util::FieldHash or ties

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Util/FieldHash/Compat/.packlist

# This package was added after Perl 5.10 became the minimal required
# version for pkgsrc. The module Hash::Util::FieldHash is a core
# module since version 5.9.4. Thus this module/package does not need
# any of the two dependencies below.
#DEPENDS+= p5-Tie-RefHash>=1.38:../../devel/p5-Tie-RefHash
#DEPENDS+= p5-Tie-RefHash-Weak>=0.08../../devel/p5-Tie-RefHash-Weak

BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
