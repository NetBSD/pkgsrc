# $NetBSD: Makefile,v 1.16 2004/02/19 22:20:00 minskim Exp $
#

DISTNAME=       MIME-tools-5.411a
PKGNAME=        p5-${DISTNAME:S/a/.1/}
SVR4_PKGNAME=	p5mit
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zeegee.com/code/perl/MIME-tools/
COMMENT=	Perl5 modules for encoding and decoding MIME messages

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/MIME-tools-5.411
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME-tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
