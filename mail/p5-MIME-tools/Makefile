# $NetBSD: Makefile,v 1.10 2002/10/20 17:46:00 seb Exp $
#

DISTNAME=       MIME-tools-5.411a
PKGNAME=        p5-${DISTNAME:S/a/.1/}
SVR4_PKGNAME=	p5mit
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zeegee.com/code/perl/MIME-tools/
COMMENT=	perl5 modules for encoding and decoding MIME messages

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MIME-tools/.packlist

WRKSRC=		${WRKDIR}/MIME-tools-5.411

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
