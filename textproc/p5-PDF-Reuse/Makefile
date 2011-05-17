# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 22:03:37 dmcmahill Exp $

DISTNAME=	PDF-Reuse-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LA/LARSLUND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Reuse
COMMENT=	Reuse and mass produce PDF documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	perl>=5.9.3,p5-IO-Compress:../../devel/p5-IO-Compress
DEPENDS+=	perl>=5.7.3,p5-Digest-MD5:../../security/p5-Digest-MD5
DEPENDS+=	p5-Text-PDF:../../textproc/p5-Text-PDF
DEPENDS+=	p5-Font-TTF:../../fonts/p5-Font-TTF

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PDF/Reuse/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
