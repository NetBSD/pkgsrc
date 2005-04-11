# $NetBSD: Makefile,v 1.20 2005/04/11 21:46:21 tv Exp $
#

DISTNAME=       MIME-tools-5.415
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5mit
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-tools/
COMMENT=	Perl5 modules for encoding and decoding MIME messages

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64>=3.03:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME-tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
