# $NetBSD: Makefile,v 1.3 2001/02/17 18:24:58 wiz Exp $
#

DISTNAME=       MIME-tools-4.124
PKGNAME=        p5-MIME-tools-4.124
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 modules for encoding and decoding MIME messages

DEPENDS+=	p5-IO-stringy-*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MIME-Base64-*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-*:../../mail/p5-MailTools

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MIME-tools/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
