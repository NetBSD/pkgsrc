# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 18:14:02 tv Exp $
#

DISTNAME=	Sendmail-PMilter-0.93
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Pure-Perl Milter protocol API

# Though it doesn't exist yet, just in case:
CONFLICTS+=	p5-Sendmail-Milter-[0-9]*

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Sendmail/PMilter/.packlist
PERL5_REQD+=	5.6.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
