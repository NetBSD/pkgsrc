# $NetBSD: Makefile,v 1.4 2001/05/17 00:44:47 jtb Exp $
#

DISTNAME=       MIME-tools-5.410
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zeegee.com/code/perl/MIME-tools/
COMMENT=	perl5 modules for encoding and decoding MIME messages

DEPENDS+=	p5-IO-stringy-*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-*:../../mail/p5-MailTools

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MIME-tools/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
