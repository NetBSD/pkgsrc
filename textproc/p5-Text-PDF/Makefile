# $NetBSD: Makefile,v 1.18 2018/08/22 09:47:01 wiz Exp $
#

DISTNAME=	Text-PDF-0.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-PDF/
COMMENT=	Perl 5 module for manipulating PDF files

USE_LANGUAGES=	# empty

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=0

PERL5_PACKLIST=	auto/Text/PDF/.packlist

# Fix permissions after extraction
post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
