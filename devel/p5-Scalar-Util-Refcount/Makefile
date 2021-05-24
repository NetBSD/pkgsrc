# $NetBSD: Makefile,v 1.17 2021/05/24 19:51:31 wiz Exp $
#

DISTNAME=		Scalar-Util-Refcount-1.0.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JN/JNIXON/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/release/JNIXON/Scalar-Util-Refcount-${PKGVERSION_NOREV}/Refcount.pm
HOMEPAGE=		https://metacpan.org/pod/release/JNIXON/Scalar-Util-Refcount-1.0.2/Refcount.pm
COMMENT=		Perl module to show an object's reference count

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Scalar/Util/Refcount/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
