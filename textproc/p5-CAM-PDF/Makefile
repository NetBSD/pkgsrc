# $NetBSD: Makefile,v 1.30 2022/06/28 11:36:13 wiz Exp $

DISTNAME=	CAM-PDF-1.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CD/CDOLAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CAM-PDF
COMMENT=	Perl 5 PDF manipulation library
LICENSE=	${PERL5_LICENSE}

# Workaround for WRKREF error
#USE_TOOLS+=	csh:run

REPLACE_CSH=	bin/asciify

DEPENDS+=	p5-Crypt-RC4>=2.02:../../security/p5-Crypt-RC4
DEPENDS+=	p5-Text-PDF>=0.29:../../textproc/p5-Text-PDF
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.16}:../../security/p5-Digest-MD5

PERL5_PACKLIST=	auto/CAM/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
