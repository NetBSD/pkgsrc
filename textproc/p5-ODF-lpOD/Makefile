# $NetBSD: Makefile,v 1.2 2019/08/11 13:23:33 wiz Exp $

DISTNAME=	ODF-lpOD-1.126
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ODF/}

MAINTAINER=	ef@math.uni-bonn.de
LICENSE=	gnu-gpl-v3 AND apache-2.0
HOMEPAGE=	https://metacpan.org/pod/distribution/ODF-lpOD/lpOD.pod
COMMENT=	OpenDocument management interface

DEPENDS+=	p5-XML-Twig>=3.34:../../textproc/p5-XML-Twig
DEPENDS+=	p5-Archive-Zip>=1.30:../../archivers/p5-Archive-Zip
# File::Temp>=0.12
# File::Find>=1.01
# Time::Local>=1.07
# File::Basename>=2.76
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-File-Type-[0-9]*:../../devel/p5-File-Type
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/ODF/lpOD/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
