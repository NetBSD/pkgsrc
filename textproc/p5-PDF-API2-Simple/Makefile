# $NetBSD: Makefile,v 1.5 2012/09/03 11:16:24 sno Exp $

DISTNAME=	PDF-API2-Simple-1.1.4u
WRKSRC=		${WRKDIR}/${DISTNAME:S/u$//}
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2-Simple/
COMMENT=	Simplistic wrapper for the Perl5 PDF::API2 modules
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-PDF-API2>=2.019:../../textproc/p5-PDF-API2

PERL5_PACKLIST=	auto/PDF/API2/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
