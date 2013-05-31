# $NetBSD: Makefile,v 1.11 2013/05/31 12:41:39 wiz Exp $

DISTNAME=	Net-LibIDN-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LibIDN/
COMMENT=	Perl bindings for GNU Libidn
LICENSE=	artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_PARAMS.makemaker+=	--with-libidn=${BUILDLINK_PREFIX.libidn}/lib
MAKE_PARAMS.makemaker+=	--with-libidn-inc=${BUILDLINK_PREFIX.libidn}/include

PERL5_PACKLIST=		auto/Net/LibIDN/.packlist

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
