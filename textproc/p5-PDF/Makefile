# $NetBSD: Makefile,v 1.34 2023/07/06 09:41:42 wiz Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
PKGREVISION=	17
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/PDF
COMMENT=	Perl5 module for pdf document manipulation

WRKSRC=			${WRKDIR}/PDF
PERL5_PACKLIST=		auto/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
