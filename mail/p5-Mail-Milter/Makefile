# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 18:30:59 tv Exp $
#

DISTNAME=	Mail-Milter-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/} \
		${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Sendmail::Milter enhancement API modules

DEPENDS+=	p5-Sendmail-PMilter>=0.90:../../mail/p5-Sendmail-PMilter

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Milter/.packlist
PERL5_REQD+=	5.6.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
