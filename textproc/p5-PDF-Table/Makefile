# $NetBSD: Makefile,v 1.9 2015/06/12 10:51:26 wiz Exp $

DISTNAME=	PDF-Table-0.9.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Table/
COMMENT=	Utility class for building table layouts in a Perl5 PDF::API2 object
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PDF-API2>=2.019:../../textproc/p5-PDF-API2

WRKSRC=		${WRKDIR}/PDF-Table-Version_${PKGVERSION_NOREV}

PERL5_PACKLIST=	auto/PDF/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
