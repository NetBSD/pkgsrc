# $NetBSD: Makefile,v 1.15 2004/01/20 12:19:43 agc Exp $
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

WRKSRC=			${WRKDIR}/MIME-tools-5.411
USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME-tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
