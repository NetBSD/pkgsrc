# $NetBSD: Makefile,v 1.10 2016/06/08 19:23:25 wiz Exp $

DISTNAME=	PerlIO-gzip-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl extension to provide a PerlIO layer to gzip/gunzip
HOMEPAGE=	http://search.cpan.org/dist/PerlIO-gzip/
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=	c

PERL5_PACKLIST=		auto/PerlIO/gzip/.packlist

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
