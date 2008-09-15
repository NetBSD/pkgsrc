# $NetBSD: Makefile,v 1.1.1.1 2008/09/15 14:57:28 he Exp $

DISTNAME=	Net-LibIDN-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LibIDN/
COMMENT=	Perl bindings for GNU Libidn

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_PARAMS.makemaker+=	--with-libidn=${PREFIX}/lib
MAKE_PARAMS.makemaker+=	--with-libidn-inc=${PREFIX}/include

PERL5_PACKLIST=		auto/Net/LibIDN/.packlist

.include "../../devel/libidn/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
