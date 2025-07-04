# $NetBSD: Makefile,v 1.28 2025/07/04 08:47:44 wiz Exp $

DISTNAME=	Net-LibIDN-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	17
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-LibIDN
COMMENT=	Perl bindings for GNU Libidn
LICENSE=	artistic

MAKE_PARAMS.makemaker+=	--with-libidn=${BUILDLINK_PREFIX.libidn}/lib
MAKE_PARAMS.makemaker+=	--with-libidn-inc=${BUILDLINK_PREFIX.libidn}/include

PERL5_PACKLIST=		auto/Net/LibIDN/.packlist

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath+=	Makefile.PL
SUBST_VARS.rpath+=	COMPILER_RPATH_FLAG

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
