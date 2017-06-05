# $NetBSD: Makefile,v 1.23 2017/06/05 14:24:38 ryoon Exp $

DISTNAME=	CAM-PDF-1.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CD/CDOLAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CAM-PDF/
COMMENT=	Perl 5 PDF manipulation library
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	csh:run

REPLACE_CSH=	bin/asciify

DEPENDS+=	p5-Crypt-RC4>=2.02:../../security/p5-Crypt-RC4
DEPENDS+=	p5-Text-PDF>=0.29:../../textproc/p5-Text-PDF
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5>=2.16}:../../security/p5-Digest-MD5

PERL5_PACKLIST=	auto/CAM/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
