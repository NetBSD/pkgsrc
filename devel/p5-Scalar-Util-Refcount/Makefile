# $NetBSD: Makefile,v 1.16 2020/09/08 13:16:38 wiz Exp $
#

DISTNAME=		Scalar-Util-Refcount-1.0.2
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
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
