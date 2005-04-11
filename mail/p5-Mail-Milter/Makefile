# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:21 tv Exp $
#

DISTNAME=	Mail-Milter-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/} \
		${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Sendmail::Milter enhancement API modules

DEPENDS+=	p5-Sendmail-PMilter>=0.90:../../mail/p5-Sendmail-PMilter

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Milter/.packlist
PERL5_REQD+=	5.6.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
