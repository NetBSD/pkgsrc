# $NetBSD: Makefile,v 1.6 2002/10/31 08:18:40 seb Exp $
#

DISTNAME=	grepmail-4.80
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	mbox formatted file search utility

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/grepmail/.packlist

MAKE_PARAMS+=	INSTALLDIRS=site
MAKE_PARAMS+=	FASTREADER=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
