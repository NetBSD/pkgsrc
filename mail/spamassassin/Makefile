# $NetBSD: Makefile,v 1.1.1.1 2002/08/24 19:46:39 hubertf Exp $
#

DISTNAME=	Mail-SpamAssassin-2.31
PKGNAME=	spamassassin-2.31
CATEGORIES=	mail perl5
MASTER_SITES=	http://spamassassin.taint.org/released/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://spamassassin.taint.org/
COMMENT=	Spam identifier and blocker

DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/SpamAssassin/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
