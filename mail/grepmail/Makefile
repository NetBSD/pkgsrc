# $NetBSD: Makefile,v 1.11 2004/05/02 04:19:41 snj Exp $
#

DISTNAME=	grepmail-5.22
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	mbox formatted file search utility

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
DEPENDS+=	p5-Inline-[0-9]*:../../devel/p5-Inline
DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/grepmail/.packlist

MAKE_PARAMS+=	INSTALLDIRS=site

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
