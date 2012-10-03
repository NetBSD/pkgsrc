# $NetBSD: Makefile,v 1.9 2012/10/03 21:57:03 wiz Exp $

DISTNAME=	Net-LibIDN-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LibIDN/
COMMENT=	Perl bindings for GNU Libidn
LICENSE=	artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS.makemaker+=	--with-libidn=${BUILDLINK_PREFIX.libidn}/lib
MAKE_PARAMS.makemaker+=	--with-libidn-inc=${BUILDLINK_PREFIX.libidn}/include

PERL5_PACKLIST=		auto/Net/LibIDN/.packlist

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
