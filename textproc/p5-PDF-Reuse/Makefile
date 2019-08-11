# $NetBSD: Makefile,v 1.17 2019/08/11 13:23:33 wiz Exp $

DISTNAME=	PDF-Reuse-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PDF-Reuse
COMMENT=	Reuse and mass produce PDF documents
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress-[0-9]*}:../../devel/p5-IO-Compress
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]}}:../../security/p5-Digest-MD5
DEPENDS+=	p5-Text-PDF-[0-9]*:../../textproc/p5-Text-PDF
DEPENDS+=	p5-Font-TTF-[0-9]*:../../fonts/p5-Font-TTF

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PDF/Reuse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
